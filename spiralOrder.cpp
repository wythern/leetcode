#include "common.h"

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > matrix(n, vector<int>(n, 0));
		generateMatrixImpl(matrix, n, 0, 0, 1);
		return matrix;
    }

	void generateMatrixImpl(vector<vector<int> > &matrix, int n, int x, int y, int v){
		if (n <= 0)
			return;

		for(int i = 0; i < n; ++i){
			matrix[y][x + i] = v++;
		}

		for(int i = 1; i < n; ++i){
			matrix[y + i][x + n - 1] = v++;
		}

		for(int i = n - 2; i >= 0; --i){
			matrix[y + n - 1][x + i] = v++;
		}

		for(int i = n - 2; i >= 1; --i){
			matrix[y + i][x] = v++;
		}

		generateMatrixImpl(matrix, n - 2, x + 1, y + 1, v);
	}

	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		if(matrix.empty())
			return vector<int>();

		return spiralOrderImpl(matrix, matrix[0].size(), matrix.size(), 0, 0);
    }

	vector<int> spiralOrderImpl(vector<vector<int> > &matrix, int m, int n, int x, int y){
		if(m <= 0 || n <= 0){
			return vector<int>();
		}

		vector<int> vSpiralMatrix;
		//vSpiralMatrix.insert(vSpiralMatrix.end(), matrix[y].begin() + x, matrix[y].begin() + x + m);
		for(int i = 0; i < m; ++i){
			vSpiralMatrix.push_back(matrix[y][x + i]);
		}
		for(int i = 1; i < n; ++i){
			vSpiralMatrix.push_back(matrix[y+i][x + m - 1]);
		}
		for(int i = m - 2; i >= 0 && n > 1; --i){
			vSpiralMatrix.push_back(matrix[y + n - 1][x + i]);
		}

		//vSpiralMatrix.insert(vSpiralMatrix.end(), matrix[y].rbegin() + x + 1, matrix[y].rbegin() + x + m);
		for(int i = n - 2; i >= 1 && m > 1; --i){
			vSpiralMatrix.push_back(matrix[y + i][x]);
		}

		vector<int> vSpiralSubMatrix = spiralOrderImpl(matrix, m - 2, n - 2, x + 1, y + 1);

		vSpiralMatrix.insert(vSpiralMatrix.end(), vSpiralSubMatrix.begin(), vSpiralSubMatrix.end());
		return vSpiralMatrix;
	}
	
};

int main(int argc, char** argv){
	//const int p[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	//const int p[][3] = {{1, 2, 3}};
	const int p[][2] = {{1, 2}, {3, 4}};
	vector<vector<int> > matrix;
	for(int i = 0; i < sizeof(p)/sizeof(p[0]); ++i){
		matrix.push_back(vector<int>(p[i], p[i] + sizeof(p[i])/sizeof(p[i][0])));
	}
	Solution s;
	//vector<int> vSpiralMatrix(s.spiralOrder(matrix));
	//printContainer<vector<int> >(vSpiralMatrix, vSpiralMatrix.size(), "S");
	int n = 4;
	vector<vector<int> > m = s.generateMatrix(n);

	for(int i = 0; i < n; ++i){
		printContainer<vector<int> > (m[i], m[i].size(), "m");
	}
	
	return 0;
}
