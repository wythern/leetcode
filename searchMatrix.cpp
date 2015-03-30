#include "common.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int len = matrix.size()*matrix[0].size();
		if(target >= getElement(matrix, 0) && target <= getElement(matrix, len - 1))
			return searchMatrixImpl(matrix, 0, len - 1, target);
		else
			return false;
    }

	bool searchMatrixImpl(vector<vector<int> > &matrix, int start, int end, int target) {
		if(end < start)
			return false;

		int k = start + (end-start)/2;
		if(getElement(matrix, k) == target)
			return true;
		else if(getElement(matrix, k) > target)
			return searchMatrixImpl(matrix, start, k - 1, target);
		else
			return searchMatrixImpl(matrix, k + 1, end, target);
	}

	int getElement(vector<vector<int> > &matrix, int idx){
		//int r = matrix.size();
		int c = matrix[0].size();
		return matrix[idx/c][idx%c];
	}
};

int main(int argc, char** argv){
#if 0
	int array[][4] = {{  1,  3,  5,  7},
					  { 10, 12, 13, 15}, 
					  { 21, 23, 25, 27}};
#endif
	int array[][1] = {{1}};


	vector<vector<int> > grid;
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); ++i){
		vector<int> v(array[i], array[i] + 1);
		grid.push_back(v);
	}

	Solution s;
	int target = (argc > 1) ? (atoi(argv[1])) : 3;
	cout << string(s.searchMatrix(grid, target) ? "FOUND." : "NOT Found!") << endl;
	return 0;
}
