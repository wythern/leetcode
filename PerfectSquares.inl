#include "common.h"

class Solution {
public:
	int numSquares(int n) {
		int m = sqrt(n);
		vector<int> vM(m + 1, 0);
		vector<int> vN(n + 1, -1);
		for (size_t i = 1; i <= m; i++)
		{
			vM[i] = i*i;
		}

		return numSquaresImpl(n, vM, vN);
	}

	int numSquaresImpl(int n, vector<int>& vM, vector<int>& vN){
		if (n <= 0)
			return n;

		if (vN[n] != -1)
			return vN[n];

		int minCnt = INT_MAX;
		int k = sqrt(n);
		for (size_t i = 1; i <= k; i++)
		{
			int cnt = numSquaresImpl(n - vM[i], vM, vN) + 1;
			if (cnt >= 0 && cnt < minCnt)
				minCnt = cnt;
		}

		vN[n] = minCnt;
		return minCnt;
	}
};

int main(int argc, char** argv){
	Solution s;
	cout << s.numSquares(257) << endl;
	return 0;
}