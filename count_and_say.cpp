#include "common.h"

class Solution {
public:
    string countAndSay(int n) {
		std::ostringstream ss;
		ss << 1;
		string say = ss.str();
        for (int i = 2; i <= n; ++i){
            say = countAndsay(say);
        }
        return say;
    }
    
    string countAndsay(string number) {
		cout << "the number string is " << number << endl;
		int n = number[0] - '0';
		int count = 1;
		string say("");
        for(int i = 1; i < number.size(); ++i) {
			if(n != number[i] - '0'){
				std::ostringstream ss;
				ss << count << n;
				say += ss.str();
				n = number[i] - '0';
				count = 1;
			}else{
				count++;
			}
        }

		// tail one.
		std::ostringstream ss;
		ss << count << n;
		say += ss.str();
        return say;
    }
};	

int main(int argc, char** argv){
	if(argc < 2)
		return 0;

	Solution s;
	cout << s.countAndSay(atoi(argv[1])) << endl;
	return 0;
}
