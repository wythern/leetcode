#include "common.h"

class Solution {
public:
	string shortestPalindrome(string s) {
		if (isPalindrome(s))
			return s;

		cout << 1234 << endl;

		pfcout << "----------------------";
		for (size_t i = s.size() - 1; i > 0; i--)
		{
			if (isPalindrome(s.substr(0, i)))
				return reverseString(s.substr(i)) + s;
		}
	}

	string shortestPalindrome_BF(string s) {
		string newString = s;
		for (size_t i = s.size() - 1; i > 0; i--)
		{
			newString = reverseString(s.substr(i)) + newString;
			if (isPalindrome(newString))
				return newString;
		}
	}

	string reverseString(string& s){
		string reverseS;
		int i = s.size() - 1;
		while (i >= 0)
		{
			reverseS.push_back(s[i]);
			--i;
		}
		return reverseS;
	}

	bool isPalindrome(string& s){
		int i = 0;
		int j = s.size() - 1;
		while (i < j){
			if (s[i] != s[j])
				return false;
			++i;
			--j;
		}

		return true;
	}
};

int main(int argc, char** argv){
	Solution s;
	string str("");
	for (int i = 0; i < 1000000; i++)
	{
		if (i == 500001)
			str.push_back('b');
		str.push_back('a');
	}
	s.shortestPalindrome(str);
	pfcout << "endl";
	return 0;
}