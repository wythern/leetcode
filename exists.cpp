#include "common.h"

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
		vector<vector<int> > status;
		for(int i = 0; i < board.size(); ++i){
			status.push_back(vector<int>(board[0].size(), word.size()));
		}

		for(int i = 0; i < board.size(); ++i){
			for(int j = 0; j < board[0].size(); ++j){
				if(findStringOnBoard(board, word, i, j)){
					return true;
				}
			}
		}
		return false;
    }

	bool findStringOnBoard(vector<vector<char> > &board, string word, int i, int j){
		if(word.empty())
			return true;

		if(word[0] != board[i][j]){
			return false;
		}

		char ch = board[i][j];
		board[i][j] = '.';
		for(int m = i - 1; m <= i + 1; ++m)
			for(int n = j - 1; n <= j + 1; ++n){
				if(m == i && n == j)
					continue;

				if((m >= 0 && m < board.size()) &&
				   (n >= 0 && n < board[0].size())){
					string newWord(word.begin() + 1, word.end());
					if(findStringOnBoard(board, newWord, m, n))
						return true;
				}
			}

		board[i][j] = ch;
		return false;
	}
};

int main(int argc, char** argv){
	string word("SEE");
	if(argc > 1)
		word = string(argv[1]);
		
	const char* p[] = {"aaaa","aaaa","aaaa","aaaa","aaab"};
	Solution s;
	vector<vector<char> > strs;
	for(int i = 0; i < 3; ++i){
		strs.push_back(vector<char>(p[i], p[i] + strlen(p[i])));
	}

	cout << string(s.exist(strs, word) ? "Find" : "NOT Find.") << endl;

	return 0;
}
