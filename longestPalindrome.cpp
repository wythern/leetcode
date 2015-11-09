#include "common.h"

using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
		int nMaxLength = 1;
		std::string strLongPalindrome(s, 0, 1);
		for(int pos = 0; pos < s.length(); ++pos){
			int i = -1;
			int j = -1;

			// either ABBA palindrome
			if(isTypeABBA(s, pos)){
				i = pos;
				j = pos + 1;
				while((i >= 0) && (j <= s.length() - 1) && (s[i] == s[j])){
					--i;
					++j;
				}

				++i;
				--j;
				if((j-i+1) > nMaxLength){
					strLongPalindrome = std::string(s, i, j-i+1);
					nMaxLength = j-i+1;
				}
			}

			// or ABA palindrome
			if (isTypeABA(s, pos)){
				i = pos - 1;
				j = pos + 1;
				while((i >= 0) && (j <= s.length() - 1) && (s[i] == s[j])){
					--i;
					++j;
				}

				++i;
				--j;
				if((j-i+1) > nMaxLength){
					strLongPalindrome = std::string(s, i, j-i+1);
					nMaxLength = j-i+1;
				}
			}
		}

		return strLongPalindrome;
    }

	bool isTypeABBA(string s, int pos)
	{
		if(s.length() == pos)
			return false;

		if(s[pos] == s[pos + 1]){
			return true;
		}else{
			return false;
		}
	}

	bool isTypeABA(string s, int pos)
	{
		if(0 == pos || s.length() == pos)
			return false;

		if(s[pos - 1] == s[pos + 1]){
			return true;
		}else{
			return false;
		}
	}

};


int main(int argc, char** argv)
{
	Solution s;
	std::string strInput("abbaccabbaabbaccabba");
	//std::cin >> strInput;
	std::string strResult = s.longestPalindrome(strInput);

	std::cout << strResult << std::endl;
	return 0;
}
