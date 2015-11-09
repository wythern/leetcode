#include "common.h"

class Solution {
public:
	enum{
		INTEGER  = 1,
		DECIMAL  = 2,
		NOTATION = 4,
		SIGNMAKR = 8,
	};

    bool isNumber(string s) {
		int l = s.find_first_not_of(' ');
		int r = s.find_last_not_of(' ');
		string candidate(s.begin() + l, s.begin() + r + 1);
		return isNumberImpl(candidate);
    }

	bool isNumberImpl(string s){
		string::iterator p = s.begin();
		int status = 0;
		while(p != s.end()){
			if(*p == '+' || *p == '-'){
				if((status & SIGNMAKR) || (status & INTEGER) || ((status & DECIMAL) && !(status & NOTATION)))
					return false;
				status |= SIGNMAKR;
			}else if(*p >= '0' && *p <= '9'){
				status |= INTEGER;
			}else if(*p == 'e'){
				if((status & NOTATION) || !(status & INTEGER))
					return false;
				status |= NOTATION;
				status &= ~INTEGER;
				status &= ~SIGNMAKR;
			}else if(*p == '.'){
				if((status & DECIMAL) || (status & NOTATION))
					return false;
				status |= DECIMAL;
			}else
				return false;

			++p;
		}

		return status & INTEGER;
	}
};


int main(int argc, char** argv){
	if(argc < 2){
		exit(0);
	}

	string num(argv[1]);
	Solution s;
	cout << string(s.isNumber(num) ? "Yes" : "NO!") << endl;
	return 0;
}
