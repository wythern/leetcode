#include "common.h"


class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> forthNums(nums.size(), 1);
		vector<int> backNums(nums.size(), 1);

		int N = nums.size();
		for (size_t i = 1; i < N; i++)
		{
			forthNums[i] = nums[i - 1] * forthNums[i - 1];
			backNums[N - 1 - i] = backNums[N - i] * nums[N - i];
		}

		vector<int> products(forthNums);
		for (size_t i = 0; i < N; i++)
		{
			products[i] *= backNums[i];
		}
		return products;
	}

#if 0
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> output(nums.size(), 0);
		pMatrix = new vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));

		for (int i = 0; i < nums.size(); ++i){
			output[i] = productNums(0, i, nums) * productNums(i + 1, nums.size(), nums);
		}
		return output;
	}

	int productNums(int s, int e, vector<int>& nums){
		if (s >= e || e - 1 < 0)
			return 1;

		if ((*pMatrix)[s][e - 1] != -1)
			return (*pMatrix)[s][e - 1];

		int r = nums[s] * productNums(s + 1, e, nums);
		(*pMatrix)[s][e - 1] = r;
		return r;
	}

#endif
private:
	vector<vector<int>>* pMatrix;

};


int main(int argc, char** argv){
	Solution s;
	int A[] = { 1, 2, 3, 4, 5 };
	vector<int> vA(A, A + sizeof(A) / sizeof(int));
	vector<int> v(s.productExceptSelf(vA));
	printContainer<vector<int>>(v, v.size());
	return 0;
}
