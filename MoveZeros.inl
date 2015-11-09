#include "common.h"

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int i = 0;
		int j = 0;
		while (i < nums.size()){
			if (nums[i] != 0){
				nums[j] = nums[i];
				j++;
			}

			i++;
		}

		while (j < nums.size())
		{
			nums[j] = 0;
			++j;
		}

		return;
	}
};


int main(int argc, char** argv){
	Solution s;
	int A[] = { 1, 0, 0, 0, 3, 0, 12 };
	vector<int> vA(A, A + sizeof(A) / sizeof(int));
	s.moveZeroes(vA);
	printContainer<vector<int>>(vA, vA.size());
	return 0;
}


