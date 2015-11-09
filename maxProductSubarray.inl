#include "common.h"

class Solution {
public:
	/*
	2, 3, -2, 4

	dp[i]: end with i, max product;
	dm[i]: end with i, min(minus) product;

	dp[i + 1] = (a[i] > 0) ? dp[i]*a[i] : dm[i]*a[i];
	dm[i + 1] = (a[i] > 0) ? dm[i]*a[i] : dp[i]*a[i];

	max dp[0 ... N];
	*/
	int maxProduct(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);
		vector<int> dm(nums.size(), 1);
		vector<int>& a = nums;
		dp[0] = a[0];
		dm[0] = a[0];
		int product = dp[0];
		for (size_t i = 0; i < nums.size() - 1; i++)
		{
			dp[i + 1] = std::max(dp[i] * a[i + 1], dm[i] * a[i + 1]);
			dp[i + 1] = std::max(dp[i + 1], a[i + 1]);
			dm[i + 1] = std::min(dm[i] * a[i + 1], dp[i] * a[i + 1]);
			dm[i + 1] = std::min(dm[i + 1], a[i + 1]);
			if (product < dp[i + 1])
				product = dp[i + 1];
		}
		return product;
	}
};

int main(int argc, char** argv){
	int A[] = {-2, 1, -1, 0, 3};
	vector<int> nums(A, A + sizeof(A) / sizeof(int));
	Solution s;
	cout << s.maxProduct(nums) << endl;
	return 0;
}
