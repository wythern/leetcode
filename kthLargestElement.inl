#include "common.h"

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return findKthLargestImpl(nums, 0, nums.size() - 1, k);
	}

	int findKthLargestImpl(vector<int>& nums, int s, int e, int k){
		int pos = e + 1 - k;
		int i = select(nums, s, e, pos);
		if (i == pos)
			return nums[i];
		else if (i > pos)
			return findKthLargestImpl(nums, s, i - 1, i - pos);
		else
			return findKthLargestImpl(nums, i + 1, e, k);
	}

	int select(vector<int>& nums, int s, int e, int k){
		if (s == e)
			return s;

		int i = s + 1;
		int j = e;

		int m = nums[s];
		while (i < j){
			while (nums[i] < m && i < e) ++i;
			while (nums[j] > m && j > s) --j;
			if (i < j){
				swap(nums[i], nums[j]);
			} else
				break;
		}
		swap(nums[j], nums[s]);
		return j;
	}

};


int main(int argc, char** argv){
	Solution s;
	//int A[] = { 3, 3 };
	int A[] = { 5, 2, 4, 1, 3, 6, 0};

	vector<int> vA(A, A + sizeof(A) / sizeof(int));
	pfcout << s.findKthLargest(vA, 2);
	
	return 0;
}