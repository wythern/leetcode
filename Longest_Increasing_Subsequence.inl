#include "common.h"

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int N = nums.size();
		if (!N)
			return 0;

		vector<int> dpNum(N, 1);
		dpNum[0] = 1;
		for (size_t i = 1; i < N; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				if (nums[i] > nums[j]){
					dpNum[i] = std::max(dpNum[j] + 1, dpNum[i]);
				}
			}
		}

		return *(std::max_element(dpNum.begin(), dpNum.end()));
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[] = { 100, 120, 0, 2, 50, 3 };
	vector<int> vA(A, A + sizeof(A)/sizeof(int));
	pfcout << s.lengthOfLIS(vA);

	return 0;
}
