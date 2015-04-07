#include "common.h"

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
		for(int i = 0; i < board.size(); ++i){
			for(int j = 0; j < board[0].size(); ++j){
				if(findStringOnBoard(board, word.c_str(), i, j)){
					return true;
				}
			}
		}
		return false;
    }

	bool findStringOnBoard(vector<vector<char> > &board, const char* word, int i, int j){
		if(*word == '\0')
			return true;

		if((i < 0 || i >= board.size()) || (j < 0 || j >= board[0].size()))
			return false;

		if(word[0] != board[i][j]){
			return false;
		}

		char ch = board[i][j];
		board[i][j] = '.';
		for(int m = i - 1; m <= i + 1; ++m)
			for(int n = j - 1; n <= j + 1; ++n){
				if((m == i && n == j) ||
				   (m == i - 1 && n == j - 1) ||
				   (m == i + 1 && n == j - 1) ||
				   (m == i + 1 && n == j + 1) ||
				   (m == i - 1 && n == j + 1))
					continue;

				if(findStringOnBoard(board, word+1, m, n))
					return true;
			}

		board[i][j] = ch;
		return false;
	}
};

int main(int argc, char** argv){
	string word("SEE");
	if(argc > 1)
		word = string(argv[1]);

#if 1
	const char* p[] = {"aaaa","aaaa","aaaa","aaaa","aaab"};
	Solution s;
	vector<vector<char> > strs;
	for(int i = 0; i < 5; ++i){
		strs.push_back(vector<char>(p[i], p[i] + strlen(p[i])));
	}
#endif

#if 0
	const char* p[] = {"ABCE",
					   "SFES",
					   "ADEE",
					   "MNOP",
					   "QRST"};

	Solution s;
	vector<vector<char> > strs;
	for(int i = 0; i < 5; ++i){
		strs.push_back(vector<char>(p[i], p[i] + strlen(p[i])));
	}
#endif

#if 0
	Solution s;
	vector<vector<char> > strs;
	strs.push_back(vector<char>(1, 'a'));
#endif

	cout << string(s.exist(strs, word) ? "Find" : "NOT Find.") << endl;

	return 0;
}
