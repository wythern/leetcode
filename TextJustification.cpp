#include "common.h"

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		if (words.empty() || maxWidth < 0)
			return vector<string>();

		vector<string> vJustfiedString;
		return fullJustifyImpl(0, words.size(), words, maxWidth, vJustfiedString);
	}

	vector<string> fullJustifyImpl(int s, int e, vector<string>& words, int l, vector<string> vJustfiedString){
		if (s >= e || words[s].size() > l)
			return vJustfiedString;

		int wordslen = words[s].size();
		int i = s;
		int wordscnt = 1;
		while (i + 1 < e && wordslen + words[i + 1].size() + wordscnt <= l)
		{
			++i;
			wordslen += words[i].size();
			++wordscnt;
		}

		string strOneLine("");
		if (i == e - 1 || wordscnt == 1) {
			//reach end;
			while (wordscnt--) {
				strOneLine += words[i - wordscnt];
				if(wordscnt) strOneLine += string(" ");
			}
			strOneLine += string(l - strOneLine.size(), ' ');
			vJustfiedString.push_back(strOneLine);
			return fullJustifyImpl(i + 1, e, words, l, vJustfiedString);
		}

		int baseSpaceCnt = (l - wordslen) / (wordscnt - 1);
		int offset = (l - wordslen) % (wordscnt - 1);
		while (wordscnt--)
		{
			strOneLine += words[i - wordscnt];
			if (wordscnt >= 1) strOneLine += string(baseSpaceCnt, ' ');
			if (offset-- > 0) strOneLine += string(" ");
		}
		vJustfiedString.push_back(strOneLine);
		return fullJustifyImpl(i + 1, e, words, l, vJustfiedString);
	}
};


int main(int argc, int** argv){
	char *p[] = { "a", "b", "c" };
	vector<string> words;
	for (int i = 0; i < sizeof(p) / sizeof(char*); ++i)
		words.push_back(p[i]);

	Solution s;
	vector<string> vJfiedString = s.fullJustify(words, 3);

	printContainer<vector<string>>(vJfiedString, vJfiedString.size(), "", true);
	return 0;
}
