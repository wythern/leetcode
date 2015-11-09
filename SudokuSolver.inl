#include "common.h"

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		vector<int> columStatus(9, 0);
		vector<int> rowStatus(9, 0);
		vector<int> cubicStatus(9, 0);

		initStatus(columStatus, rowStatus, cubicStatus, board);
		solveSudokuHelper(columStatus, rowStatus, cubicStatus, board, 0);
	}

	void initStatus(vector<int>& colStatus, vector<int>& rowStatus, vector<int>& cubicStatus, vector<vector<char>>& board){
		for (size_t i = 0; i < board.size(); i++){
			for (size_t j = 0; j < board[0].size(); ++j){
				char chNum = board[i][j];
				if (chNum != '.'){
					chNum -= '0';
					colStatus[j] |= 1 << chNum;
					rowStatus[i] |= 1 << chNum;
					cubicStatus[(i / 3) * 3 + j / 3] |= 1 << chNum;
				}
			}
		}
	}

	bool isValidTry(vector<int>& colStatus, vector<int>& rowStatus, vector<int>& cubicStatus, vector<vector<char>>& board, int row, int col, int k){
		return !((colStatus[col] & (1 << k)) || (rowStatus[row] & (1 << k)) || (cubicStatus[(row / 3) * 3 + col / 3] & (1 << k)));
	}


	bool solveSudokuHelper(vector<int>& colStatus, vector<int>& rowStatus, vector<int>& cubicStatus, vector<vector<char>>& board, int index){
		bool bTried = false;
		int curIdx = index;
		while(curIdx < 81){ // index is not begin from x when row++!!!!!!!!!!!!!!!!!!!!!!!!!!
			int y = curIdx / board[0].size();
			int x = curIdx % board[0].size();
			int row = x;
			int col = y;
			curIdx++;
			if (board[row][col] == '.'){
				bTried = true;
				for (int k = 1; k <= 9; ++k){
					if (isValidTry(colStatus, rowStatus, cubicStatus, board, row, col, k)){
						colStatus[col] |= 1 << k;
						rowStatus[row] |= 1 << k;
						cubicStatus[(row / 3) * 3 + col / 3] |= 1 << k;
						board[row][col] = k + '0';
						if (!solveSudokuHelper(colStatus, rowStatus, cubicStatus, board, curIdx)){
							colStatus[col] &= ~(1 << k);
							rowStatus[row] &= ~(1 << k);
							cubicStatus[(row / 3) * 3 + col / 3] &= ~(1 << k);
							board[row][col] = '.';
						} else{
							return true;
						}
					}
				}
				return false;
			}
		}

		return true;
	}

};


int main(int argc, char** argv){
	Solution s;
#if 0
	char A[] = {
		0x5, 0x3, '.', '.', '.', '.', '.', '.', '.',
		0x6, '.', '.', 0x1, '.', 0x5, '.', '.', '.',
		'.', 0x9, 0x8, '.', '.', '.', '.', 0x6, '.',
		0x8, '.', '.', '.', '.', '.', '.', '.', 0x3,
		0x4, '.', '.', 0x8, '.', 0x3, '.', '.', 0x1,
		0x7, '.', '.', '.', '.', '.', '.', '.', 0x6,
		'.', 0x6, '.', '.', '.', '.', 0x2, 0x8, '.',
		'.', '.', '.', 0x4, 0x1, 0x9, '.', '.', 0x5,
		'.', '.', '.', '.', 0x8, '.', '.', 0x7, 0x9,
	};
#endif
	char A[] = { "..9748...7.........2.1.9.....7...24..64.1.59..98...3.....8.3.2.........6...2759.."};

	vector<vector<char>> board(Init2DTable<char>(A, 9, 9));

	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board[0].size(); j++){
			if (board[i][j] != '.')
				cout << (int)(board[i][j] - '0') << ",";
			else
				cout << board[i][j] << ",";
		}

		cout << endl;
	}

	pfcout << "---------------------------------------------------";
	s.solveSudoku(board);
	pfcout << "---------------------------------------------------";

	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board[0].size(); j++){
			if (board[i][j] != '.')
				cout << (int)(board[i][j] - '0') << ",";
			else
				cout << board[i][j] << ",";
		}

		cout << endl;
	}

	return 0;
}

