#include "common.h"

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = 0;
		int col = matrix[0].size() - 1;

		while (row < matrix.size() && col >= 0){
			if (matrix[row][col] == target)
				return true;
			else if (matrix[row][col] > target)
				col--;
			else
				row++;
		}

		return false;
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[] = {  1,  4,  7, 11, 15, 
				 2,  5,  8, 12, 19, 
				 3,  6,  9, 16, 22, 
				10, 13, 14, 17, 24,
				18, 21, 23, 26, 30 };
	vector<vector<int>> matrix(Init2DTable<int>(A, 5, 5));
	cout << (s.searchMatrix(matrix, 30) ? "YES" : "NO") << endl;
	return 0;
}

