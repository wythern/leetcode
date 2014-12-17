#include "common.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		const char* NumberToLetter[] = {"", "",
										"abc", "def", "ghi",
										"jkl", "mno", "pqrs",
										"tuv", "wxyz", ""};

		if(digits.empty())
			return vector<string>(1, string(""));

		ResolveLetterCombinations(NumberToLetter, digits, "");
		//ResolveLetterCombinations2(NumberToLetter, digits, 0, digits.size());
		return m_vStrLetterCombinations;
    }

	void ResolveLetterCombinations(const char** NumberToLetter,
								   string digits,
								   string strCandidate){
		if(digits.empty()){
			m_vStrLetterCombinations.push_back(strCandidate);
			return;
		}

		string strLetters(NumberToLetter[digits[0] - '0']);
		for (string::iterator it = strLetters.begin();
			 it != strLetters.end();
			 ++it){
			ResolveLetterCombinations(NumberToLetter,
									  string(digits.begin() + 1, digits.end()),
									  strCandidate+(*it));
		}
	}

	void ResolveLetterCombinations2(const char** NumberToLetter, string& strLetters, int s, int e){
		if(s == e){
			m_vStrLetterCombinations.push_back(strLetters);
			return;
		}

		char currCh = strLetters[s];
		string strCandidate(NumberToLetter[currCh - '0']);
		
		for (string::iterator it = strCandidate.begin();
			 it != strCandidate.end();
			 ++it){
			strLetters[s] = *it;
			ResolveLetterCombinations2(NumberToLetter, strLetters, s+1, e);
			strLetters[s] = currCh;
		}
	}

public:
	vector<string> m_vStrLetterCombinations;
};

int main(int argc, char** argv){
	Solution s;
	vector<string> v(s.letterCombinations(argv[1]));
	printArray(v);
	return 0;
}
