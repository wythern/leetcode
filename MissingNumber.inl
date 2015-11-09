#include "common.h"

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		uint32_t sum = 0;
		uint32_t sumRef = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			sumRef += i;
		}

		sumRef += nums.size();
		return sumRef - sum;
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[] = { 0 };
	vector<int> vA(A, A + sizeof(A) / sizeof(int));
	cout << s.missingNumber(vA) << endl;
	return 0;
}