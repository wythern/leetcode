#include "common.h"

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		if(grid.empty() || grid[0].empty())
			return 0;

		for(int i = 0; i < grid.size(); ++i){
			for(int j = 0; j < grid[i].size(); ++j){
				if(i == 0 && j > 0)
					grid[i][j] += grid[i][j - 1];
				else if(j == 0 && i > 0)
					grid[i][j] += grid[i - 1][j];
				else if(i > 0 && j > 0)
					grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
			}
			printContainer<vector<int> >(grid[i], grid[i].size(), "Current");
		}

		return grid.back().back();
    }
};

int main(int argc, char** argv){
	int array[][10] ={{2,7,4,3,2,2,2,9,2,6},
					  {3,6,6,1,0,5,9,6,3,8},
					  {1,5,4,5,3,8,7,2,5,6},
					  {5,7,6,9,0,8,1,4,7,5},
					  {0,2,1,9,5,3,6,5,9,9},
					  {5,3,6,1,8,9,0,7,4,7},
					  {6,9,4,2,0,6,0,3,2,9},
					  {8,3,3,1,2,9,5,8,6,6},
					  {9,1,9,5,4,7,6,4,5,0},
					  {4,1,1,8,5,1,7,5,4,9},
					  {6,4,4,9,8,8,8,5,8,4},
					  {1,7,7,3,2,4,0,9,8,7},
					  {1,4,0,3,5,5,4,2,2,1},
					  {3,0,5,8,0,3,6,0,0,5},
					  {7,2,4,6,5,7,0,7,8,1},
					  {7,9,5,7,4,0,5,1,4,9},
					  {2,8,0,9,8,2,5,6,2,5},
					  {3,9,9,8,6,4,7,8,4,5},
					  {9,1,6,5,0,3,5,5,4,0}};

	vector<vector<int> > grid;
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); ++i){
		vector<int> v(array[i], array[i] + 3);
		grid.push_back(v);
	}
	
	Solution s;
	cout << s.minPathSum(grid) << endl;
	return 0;
}
