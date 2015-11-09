#include "common.h"

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		//WRONG Answer! NOT using log complexity algorithm.
		int peak = 0;
		for (uint32_t i = 0; i < nums.size(); ++i){
			if (isPeak(i, nums)){
					return i;
			}
		}
		return peak;
	}

	bool isPeak(int i, vector<int>& nums){
		int l = i - 1;
		int r = i + 1;
		if (l < 0 && r >= nums.size()){
			return true;
		} else if (l < 0){
			return nums[i] > nums[r];
		} else if (r >= nums.size()){
			return nums[l] < nums[i];
		} else {
			return nums[l] < nums[i] && nums[i] > nums[r];
		}
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[] = {-2147483648, -2147483647};
	vector<int> vA(A, A + sizeof(A) / sizeof(int));
	cout << s.findPeakElement(vA) << endl;
	return 0;
}