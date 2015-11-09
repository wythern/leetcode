#include "common.h"

class Solution {
public:
    int lengthOfLastWord(const char *s) {
		const char* p = s;
		int l = 0;
		int lastwordl = 0;
		while(*p != '\0'){
			if(*p == ' '){
				lastwordl = (l == 0) ? lastwordl : l;
				l = 0;
			}else if(isalpha(*p)){
				l++;
			}
			++p;
		}

		lastwordl = (l == 0) ? lastwordl : l;		
		return lastwordl;
    }
};

int main(int argc, char** argv){
	if(argc < 2){
		exit(0);
	}
	Solution s;
	cout << "Last word length = " << s.lengthOfLastWord(argv[1]) << endl;
	return 0;
}
