#include "common.h"

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int num = 0;
		for (size_t i = 0; i < grid.size(); i++)
		{
			for (size_t j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1'){
					markIsland(grid, i, j);
					num++;
				}
			}
		}
		return num;
	}

	void markIsland(vector<vector<char>>& grid, int i, int j){
		vector<pair<int, int>> coodStack(1, pair<int, int>(i, j));
		while (!coodStack.empty())
		{
			pair<int, int> cood = coodStack.back();
			coodStack.pop_back();

			int x = cood.first;
			int y = cood.second;
			grid[x][y] = '2';

			if (isValidCood(grid, x - 1, y) && grid[x - 1][y] == '1')
				coodStack.push_back(pair<int, int>(x - 1, y));
			if (isValidCood(grid, x, y - 1) && grid[x][y - 1] == '1')
				coodStack.push_back(pair<int, int>(x, y - 1));
			if (isValidCood(grid, x + 1, y) && grid[x + 1][y] == '1')
				coodStack.push_back(pair<int, int>(x + 1, y));
			if (isValidCood(grid, x, y + 1) && grid[x][y + 1] == '1')
				coodStack.push_back(pair<int, int>(x, y + 1));
		}
	}

	bool isValidCood(vector<vector<char>>& grid, int i, int j){
		return 0 <= i && i < grid.size() && 0 <= j && j < grid[0].size();
	}
};

int main(int argc, char** argv){
	Solution s;
	char* A[] = {
		"111111",
		"1OOOO1",
		"1OOOO1",
		"1OOOO1",
		"111111",
		"OOOOOO",
		"1111OO",
		"OOOOO1",
		"1OO111",
		"110111",
		"110111",
		"OO1OOO",
	};

	vector<vector<char> > board;
	for (int j = 0; j < sizeof(A) / sizeof(A[0]); ++j){
		vector<char> v;
		for (int i = 0; i < strlen(A[0]); ++i){
			v.push_back(A[j][i]);
		}
		board.push_back(v);
	}

	for (int i = 0; i < board.size(); ++i)
		printContainer<vector<char> >(board[i], board.size(), "board");	cout << s.numIslands(board) << endl;

	s.numIslands(board);
	printf("---------------------------------------------------------------\n");

	for (int i = 0; i < board.size(); ++i)
		printContainer<vector<char> >(board[i], board.size(), "board");
	return 0;
}
