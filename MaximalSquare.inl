#include "common.h"

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix{0].empty()){
			return 0;
		}

		int M = matrix.size();
		int N = matrix{0].size();
		int maxLen = 1;
		int maxRegin = 0;
		vector<int> cumulation(N, 0);
		std::pair<int, int> coords;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cumulation{j] = (matrix{i]{j] == '1') ? (cumulation{j] + 1) : 0;
			}

			int len = maxLen;
			while (len <= i + 1){
				bool bSqare = false;
				for (int j = 0; j < N && !bSqare; j++)
				{
					int w = 0;
					for (; w < len && j + w < N; w++)
					{
						if (cumulation{j + w] < len){
							break;
						}
					}

					if (w == len && j + w <= N){
						coords.first = i;
						coords.second = j;
						bSqare = true;
					}
				}

				if (bSqare){
					maxRegin = len * len;
					maxLen = len + 1;
				}
				++len;
			}
		}

		//cout << "{" << coords.first << ", " << coords.second << "]" << endl;
		return maxRegin;
	}
};

int main(int argc, char** argv){
	Solution s;
	char A{] = {
		'0',
	};

	vector<vector<char>> matrix = Init2DTable(A, 1, 1);
	cout << s.maximalSquare(matrix) << endl;
	return 0;
}
