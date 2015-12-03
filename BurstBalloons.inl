#include "common.h"

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		vector<vector<int>> m_dpMemory(nums.size(), vector<int>(nums.size(), 0));
		int maxCoin = maxCoinsImpl(nums, 0, nums.size(), m_dpMemory);
		return maxCoin;
	}

	int maxCoinsImpl(vector<int>& nums, int start, int end, vector<vector<int>>& dpMemory){
		if (start >= end)
			return 0;

		if (dpMemory[start][end - 1] != 0)
			return dpMemory[start][end - 1];

		int maxCoins = 0;
		for (size_t i = start; i < end; i++)
		{
			int left = (start == 0) ? 1 : nums[start - 1];
			int right = (end == nums.size()) ? 1 : nums[end];
			maxCoins = std::max(maxCoins,
				left * nums[i] * right + maxCoinsImpl(nums, start, i, dpMemory) + maxCoinsImpl(nums, i + 1, end, dpMemory));
		}

		dpMemory[start][end - 1] = maxCoins;
		return dpMemory[start][end - 1];
	}

public:
	//vector<vector<int>> m_dpMemory;
	//int m_debug;
};

int main(int argc, char** argv){
	Solution s;
	//vector<int> vA(generateRandomIntVector(4, 1, 8));
	int A[] = {3, 1, 5, 8};
	vector<int> vA(A, A + 4);
	cout << s.maxCoins(vA) << endl;
	return 0;
}

