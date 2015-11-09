#include "common.h"

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int x = 0;
		int y = 0;
		while (n > 0){
			rotateCycle(x, y, matrix, n);
			x++;
			y++;
			n -= 2;
		}
	}

	void rotateCycle(int x, int y, vector<vector<int>>& matrix, int n){
		vector<int> vTemp;
		for (int i = 0; i < n; i++)
		{
			vTemp.push_back(matrix[y + i][x]);
		}

		for (int i = 0; i < n; i++)
		{
			matrix[y + i][x] = matrix[y + n - 1][x + i];
		}

		for (int i = 0; i < n; i++)
		{
			matrix[y + n - 1][x + i] = matrix[y + n - 1 - i][x + n - 1];
		}

		for (int i = 0; i < n; i++)
		{
			matrix[y + n - 1 - i][x + n - 1] = matrix[y][x + n - 1 - i];
		}

		for (int i = 0; i < n; i++)
		{
			matrix[y][x + i] = vTemp[n - 1- i];
		}
	}
};


int main(int argc, char** argv){
	Solution s;
	int A[] = { 1, 3, 8, 6};
	int n = sqrt(sizeof(A) / sizeof(int));
	vector<vector<int>> matrix = Init2DTable(A, n, n);
	s.rotate(matrix);

	for (int i = 0; i < (int)matrix.size(); i++)
	{
		printContainer<vector<int>>(matrix[i], matrix[i].size());
	}
	return 0;
}