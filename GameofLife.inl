#include "common.h"

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty())
			return;

		uint32_t M = board.size();
		uint32_t N = board[0].size();
		vector<vector<int>> boardNext(M + 2, vector<int>(N + 2, 0));

		for (size_t i = 1; i <= M; i++)
		{
			for (size_t j = 1; j <= N; j++)
			{
				boardNext[i][j] = board[i - 1][j - 1];
			}
		}

		for (size_t i = 1; i <= M; i++)
		{
			for (size_t j = 1; j <= N; j++)
			{
				board[i - 1][j - 1] = updateLife(boardNext, i, j);
			}
		}
	}

	int updateLife(vector<vector<int>>& boardNext, int i, int j){
		int neigbour[] = {
			boardNext[i - 1][j - 1], boardNext[i - 1][j], boardNext[i - 1][j + 1],
			boardNext[i    ][j - 1], /*boardNext[i][j],*/ boardNext[i    ][j + 1],
			boardNext[i + 1][j - 1], boardNext[i + 1][j], boardNext[i + 1][j + 1],
		};

		uint32_t N = sizeof(neigbour) / sizeof(int);
		uint32_t sum = 0;
		for (size_t k = 0; k < N; k++)
		{
			sum += neigbour[k];
		}

		if (sum < 2 || sum > 3)
			return 0;
		else if (sum == 2)
			return boardNext[i][j];
		else // (sum == 3)
			return 1;
	}
};


int main(int argc, char** argv){
	Solution s;
	int A[] = {
		1, 0, 0, 1,
		1, 0, 1, 1,
		1, 0, 0, 1,
		1, 0, 1, 0,
		1, 0, 1, 0,
	};

	vector<vector<int>> board = Init2DTable(A, 5, 4);
	s.gameOfLife(board);
	for (int i = 0; i < board.size(); ++i)
		printContainer<vector<int>>(board[i], board.size(), "");

	return 0;
}