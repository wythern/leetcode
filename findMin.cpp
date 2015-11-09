#include "common.h"

class Solution {
public:
	int findMin(vector<int>& nums) {
		int l = 0;
		int r = nums.size() - 1;
		return findMinImpl(nums, l, r);
	}

	int findMinImpl(vector<int>& nums, int l, int r){
		if (l == r )
			return nums[l];

		if (nums[l] == nums[r]){
			int m = (l + r) / 2;
			return std::min(findMinImpl(nums, l, m), findMinImpl(nums, m + 1, r));
		} else if (nums[l] < nums[r]){
			return nums[l];
		} else{
			int m = (l + r) / 2;
			if (nums[l] <= nums[m])
				return findMinImpl(nums, m + 1, r);
			else
				return findMinImpl(nums, l + 1, m);
		}
	}
};

int main(int argc, char** argv){
	int A[] = {1, 3, 3};
	vector<int> v(A, A + sizeof(A) / sizeof(int));
	Solution s;
	cout << s.findMin(v) << endl;

	return 0;
} 