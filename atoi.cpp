#include "common.h"

class Solution {
public:
    int atoi(const char* str){
		if(NULL == str)
			return 0;

		int r = 0;
		int pos = 0;
		int c = 1;
		while(str[pos++] == ' ');
		pos--;

		if('-' == str[pos]){
			c = -1;
			pos++;
		}else if('+' == str[pos]){
		    pos++;
		}

		while(str[pos] != '\0'){
			if(str[pos] >= '0' && str[pos] <= '9'){
#if 1
				if(r > INT_MAX/10){
					//std::cout << __LINE__ << std::endl;
					//throw std::exception();
					return INT_MAX;
				}else if ( r == INT_MAX/10 ) {
					if((INT_MAX%10) < (str[pos] - '0')){
						//std::cout << __LINE__ << std::endl;
						//throw std::exception();
						return INT_MAX;
					}
				}else if ( r < INT_MIN/10 ){
					//std::cout << __LINE__ << std::endl;
					//throw std::exception();
					return INT_MIN;
				}else if ( r == INT_MIN/10 ){
					if((r* 10 - INT_MIN) < (str[pos] - '0')){
						//std::cout << __LINE__ << std::endl;
						//throw std::exception();
						return INT_MIN;
					}
				}
#endif
				r = r*10 + (str[pos] - '0') * c;
				pos++;
			}else
				break;
		}

		return r;
    }
};

int main(int argc, char** argv)
{
	Solution s;
	std::cout << atoi(argv[1]) << std::endl;
	std::cout << s.atoi(argv[1]) << std::endl;
	return 0;
}
