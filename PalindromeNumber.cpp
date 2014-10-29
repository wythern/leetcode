#include "common.h"

class Solution {
public:
    bool isPalindrome(int x) {
		if(x < 0)
			return false;
		int n = x;
		const char *p = "0123456789";
		char buffer[256];
		int len = 0;
		while(n){
			buffer[len++] = p[n%10];
			n /= 10;
		}

		for(int i = 0; i < len/2; ++i){
			if(buffer[i] != buffer[len - i - 1])
				return false;
		}
		return true;
    }
};

int main(int argc, char** argv){
	Solution s;

	int n = atoi(argv[1]);
	std::cout << n << (s.isPalindrome(n)?" IS ":" IS NOT ") << "Palindrome Number." << std::endl;
	return 0;
}
