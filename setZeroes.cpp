#include "common.h"

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		vector<int> row;
		vector<int> column;
		for(int i = 0; i < matrix.size(); ++i){
			for(int j = 0; j < matrix[i].size(); ++j){
				if(!matrix[i][j]){
					row.push_back(i);
					column.push_back(j);
				}
			}
		}

		for(int i = 0; i < row.size(); ++i){
			vector<int> v(matrix[row[i]].size(), 0);
			matrix[row[i]].swap(v);
		}

		for(int j = 0; j < column.size(); ++j){
			for(int i = 0; i < matrix.size(); ++i){
				matrix[i][column[j]] = 0;
			}
		}

		return;
    }
};

int main(int argc, char** argv){
	Solution s;
	int array[][11] ={{2,7,4,3,2,2,2,9,2,0},
					  {3,6,6,1,1,5,9,6,3,8},
					  {1,5,4,5,3,8,7,2,5,6},
					  {5,7,6,9,1,8,1,4,7,0},
					  {1,2,1,9,5,3,6,5,9,9},
					  {5,3,6,1,8,9,1,7,4,7},
					  {6,9,4,2,1,6,1,3,2,9},
					  {8,3,3,1,2,9,5,8,6,6},
					  {9,1,9,5,4,7,6,4,5,1},
					  {4,1,1,8,5,1,7,5,4,9},
					  {6,4,4,9,8,8,8,5,8,4},
					  {1,7,7,3,0,4,1,9,8,7},
					  {1,4,1,3,5,5,4,2,2,1},
					  {3,1,5,8,1,3,6,1,1,5},
					  {7,2,4,6,5,7,1,7,8,1},
					  {7,9,5,7,4,1,5,1,4,9},
					  {2,8,1,9,8,2,5,6,2,5},
					  {3,9,9,8,6,4,7,8,4,5},
					  {9,1,6,5,1,3,5,5,4,1}};
	
	vector<vector<int> > grid;
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); ++i){
		vector<int> v(array[i], array[i] + 10);
		grid.push_back(v);
	}

	s.setZeroes(grid);
	for(int i = 0; i < grid.size(); ++i)
		printContainer<vector<int> >(grid[i], grid[i].size(), "Result");
	return 0;
}
