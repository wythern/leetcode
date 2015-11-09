#include "common.h"

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int s = 0;
		for (int i = 0; i <nums.size(); ++i){
			s ^= nums[i];
		}
		return s;
	}

	int singleNumberII(vector<int>& nums) {
		/*
		 *	WRONG ANSWER!!! although AC.
		 *  An elogant solution can be count the 1' numbers!!!
		 *  Using a pre-calc truth table to further save the space.
		 */
		int s = 0;
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i += 3){
			if (nums[i] != nums[i + 1])
				return nums[i];
		}
		return nums[nums.size() - 1];
	}

	#define BIT_VALUE(a, k) (a & (1 << k))
	vector<int> singleNumberIII(vector<int>& nums) {
		int A[32] = { 0 };
		int i = 0;
		for (i = 0; i < nums.size(); ++i){
			int j = 0;
			while (j < 32){
				if (BIT_VALUE(nums[i], j)) A[j]++;
				++j;
			}
		}

		for ( i = 0; i < 32; i++)
		{
			if (A[i] % 2) break;
		}

		vector<int> singleNums(2, 0);
		for (int j = 0; j < nums.size(); j++)
		{
			if (BIT_VALUE(nums[j], i)) singleNums[0] ^= nums[j];
		}

		for (int j = 0; j < nums.size(); j++)
		{
			singleNums[1] ^= nums[j];
		}

		singleNums[1] ^= singleNums[0];
		return singleNums;
	}

	int findDuplicate_1toN(vector<int>& nums) {
		int n = nums.size();
		int sumN = (1 + n)*(n) / 2;
		int sumArray = 0;
		int xorArray = 0;
		int numMiss = 0;
		int numDup = 0;
		for (int i = 0; i < nums.size(); ++i){
			sumArray += nums[i];
			xorArray ^= nums[i];
		}

		// numDup - numMiss = sumN - sumArray;
		for (int i = 1; i <= n; i++)
		{
			xorArray ^= i;
		}

		int nonZeroPos = 0;
		while (!BIT_VALUE(xorArray, nonZeroPos))
		{
			nonZeroPos++;
		}

		xorArray = 0;
		for (int i = 1; i <= n; i++)
		{
			if (BIT_VALUE(nums[i - 1], nonZeroPos) != 0)
				xorArray ^= nums[i - 1];
		}

		for (int i = 1; i <= n; i++)
		{
			if (BIT_VALUE(i, nonZeroPos) != 0)
				xorArray ^= i;
		}

		for (int i = 0; i < n; i++)
		{
			if (nums[i] == xorArray)
				return xorArray;
		}

		return xorArray - (sumN - sumArray);
	}

	int findDuplicate(vector<int>& nums) {
		return 0;
	}

};

int main(int argc, char** argv){
	Solution s;
	int nums[] = { 8, 1, 1, 1, 2, 7, 4, 3, 1, 1 };
	vector<int> vA(nums, nums + sizeof(nums) / sizeof(int));

//	vector<int> vB = s.singleNumberIII(vA);
//	cout << "[" << vB[0] << ", " << vB[1] << "]" << endl;

	int nDup = s.findDuplicate(vA);
	cout << "Duplicated number is " << nDup << "." << endl;
	return 0;
}
