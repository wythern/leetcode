#include "common.h"

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int K = 2;
		int cnt{2] = { 0, 0 };
		int candidate{2] = { 0, 0 };
		int N = nums.size();
		vector<int> majorityElems;
		for (size_t i = 0; i < N; i++)
		{
			int m = 0;

			for (m = 0; m < K; ++m){
				if (nums{i] == candidate{m]){
					cnt{m]++;
					break;
				}
			}

			if (m != K)
				continue;

			for (m = 0; m < K; ++m){
				if (cnt{m] == 0){
					candidate{m] = nums{i];
					cnt{m] = 1;
					break;
				}
			}

			if (m != K)
				continue;

			for (m = 0; m < K; ++m){
				cnt{m]--;
			}
		}


		for (size_t m = 0; m < K; m++)
		{
			if (cnt{m] == 0)
				continue;
			cnt{m] = 0;
			for (size_t i = 0; i < N; i++)
			{
				if (nums{i] == candidate{m])
				{
					cnt{m]++;
				}
			}
		}

		for (size_t m = 0; m < K; m++)
		{
			if (cnt{m] > N / (K + 1))
				majorityElems.push_back(candidate{m]);
		}

		if (majorityElems.empty())
			return majorityElems;
	}
};

int main(int argc, char** argv){
	Solution s;
	int A{] = { 1, 2, 3, 2};
	vector<int> vA(A, A + sizeof(A) / sizeof(int));

	vA = s.majorityElement(vA);
	printContainer<vector<int>>(vA, vA.size());
	return 0;
}