#include "common.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
		return maximalRectangleImpl(matrix, 0, 0, matrix[0].size(), matrix.size());
    }

	int maximalRectangleImpl(vector<vector<char> > &matrix,
							 int l, int t, int r, int b) {
		if(l < 0 || t < 0 || r < 0 || b < 0 ||
		   l >= matrix[0].size() || t >= matrix.size() ||
		   r >= matrix[0].size() || b >= matrix.size() ||
		   l >= r || b >= t)
			return 0;

		for(int j = t; j < b; ++j)
			for(int i = l; i < r; ++i){
				if(matrix[j][i] == 0){
					return std::max(std::max(maximalRectangleImpl(matrix, l, r, t, t + j), 
											 maximalRectangleImpl(matrix, l, r, t + j + 1, b)),
									std::max(maximalRectangleImpl(matrix, l, l + i, t, b), 
											 maximalRectangleImpl(matrix, l + i + 1, r, t, b)));
				}
			}

		return (r - l)*(b - t);
	}
};

int main(int argc, char** argv){
#if 0
	int array[][4] = {{ 0, 0, 0, 0},
					  { 1, 1, 1, 1},
					  { 0, 0, 0, 0}};
#else
	int array[][1] = {{1}};
#endif


	vector<vector<int> > grid;
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); ++i){
		vector<int> v(array[i], array[i] + 1);
		grid.push_back(v);
	}

	Solution s;
	int n = s.maximalRectangle(grid);
	cout << "Rect area = " << n << endl;
	return 0;
}
