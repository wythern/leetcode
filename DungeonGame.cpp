#include "common.h"

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		if (dungeon.empty() || dungeon[0].empty())
			return 0;

		// could be use 1-line.
		vector<vector<int>> travelHP(dungeon);
		int M = dungeon.size();
		int N = dungeon[0].size();
		travelHP[M - 1][N - 1] = dungeon[M - 1][N - 1] > 0 ? 1 : 1 - dungeon[M - 1][N - 1];
		for (int i = N - 2; i >= 0; --i){
			travelHP[M - 1][i] = travelHP[M - 1][i + 1] - dungeon[M - 1][i] > 0 ? travelHP[M - 1][i + 1] - dungeon[M - 1][i] : 1;
		}

		for (int i = M - 2; i >= 0; --i)
		{
			travelHP[i][N - 1] = travelHP[i + 1][N - 1] - dungeon[i][N - 1] > 0 ? travelHP[i + 1][N - 1] - dungeon[i][N - 1] : 1;
			for (int j = N - 2; j >= 0; --j){
				travelHP[i][j] = std::min(travelHP[i + 1][j] - dungeon[i][j] > 0 ? travelHP[i + 1][j] - dungeon[i][j] : 1,
					travelHP[i][j + 1] - dungeon[i][j] > 0 ? travelHP[i][j + 1] - dungeon[i][j] : 1);
			}
		}

		return travelHP[0][0];
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
	int A[] = {
//		   1,  -2,  3,
		   //2,  -2, -2,
		   -2, -3, 3,
		   -5, -10, 1,
		   10, 30, -5,
	};
	vector<vector<int>> dungeon = Init2DTable(A, 3, 3);
	Solution s;
	cout << s.calculateMinimumHP(dungeon) << endl;
	return 0;
}
