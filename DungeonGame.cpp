#include "common.h"

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
	}
	
	int calculateMinimumHP_WRONG(vector<vector<int>>& dungeon) {
		/*
		* It's not like a right & down calculation, please take
		* the + grids into account.
		* Wrong because:
		* 1. the global minimum may not make off each local minimums.
		* 2. you did not take the positive HP into account.
		* WHAT A PITY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		*/
		vector<int> minHPs(dungeon[0].size(), 0);
		vector<int> HPs(dungeon[0].size(), 0);
		minHPs[0] = (dungeon[0][0] <= 0) ? 1 - dungeon[0][0] : 1;
		HPs[0] = (dungeon[0][0] <= 0) ? 1 : dungeon[0][0];
		for (int i = 1; i < dungeon[0].size(); ++i){
			minHPs[i] = (HPs[i - 1] + dungeon[0][i] > 0) ? minHPs[i - 1] : minHPs[i - 1] - (HPs[i - 1] + dungeon[0][i]) + 1;
			HPs[i] = (HPs[i - 1] + dungeon[0][i] > 0) ? (HPs[i - 1] + dungeon[0][i]) : 1;
		}

		for (int i = 1; i < dungeon.size(); i++)
		{
			minHPs[0] = (HPs[0] + dungeon[i][0] > 0) ? minHPs[0] : minHPs[0] - (HPs[0] + dungeon[i][0]) + 1;
			HPs[0] = (HPs[0] + dungeon[i][0] > 0) ? (HPs[0] + dungeon[i][0]) : 1;
			for (int j = 1; j < dungeon[i].size(); ++j){
				int leftPath = (HPs[j - 1] + dungeon[i][j] > 0) ? minHPs[j - 1] : minHPs[j - 1] - (HPs[j - 1] + dungeon[i][j]) + 1;
				int upperPath = (HPs[j] + dungeon[i][j] > 0) ? minHPs[j] : minHPs[j] - (HPs[j] + dungeon[i][j]) + 1;
				if (leftPath < upperPath){
					minHPs[j] = leftPath;
					HPs[j] = (HPs[j - 1] + dungeon[i][j] > 0) ? (HPs[j - 1] + dungeon[i][j]) : 1;
				} else{
					minHPs[j] = upperPath;
					HPs[j] = (HPs[j] + dungeon[i][j] > 0) ? (HPs[j] + dungeon[i][j]) : 1;
				}
			}
		}

		return minHPs.back();
	}
};

int main(int argc, char** argv){
	int A[][3] = {
#if 0
		{ -2, -3, 3 },
		{ -5, -10, 1 },
		{ 10, 30, -5 },
#endif
		{ 3, -20, 30 },
		{ -3, 4, 0 },
	};
	vector<vector<int>> dungeon = Init2DTable(&A[0][0], sizeof(A) / sizeof(A[0]), sizeof(A[0]) / sizeof(int));
	Solution s;
	cout << s.calculateMinimumHP(dungeon) << endl;
	return 0;
}
