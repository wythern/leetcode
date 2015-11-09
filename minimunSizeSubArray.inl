#include "common.h"

class Solution {
	/*
	2,3,1,2,4,3
	S = 7
	d[i][j] = sum(a[i...j]) >= 7;
	min(j - i);

	i\j		0		1		2		3
	----+------------------------------------
	0   |  	a[0]	a[0.1]	a[0.2]	a[0.3]
	1   |	X		a[1]	a[1.2]	a[1.3] 		
	2   |	X		X		a[2]	a[2.3]	
	3   |	X		X		X		a[3]

	A possible O(2N) solution is like traversal this
	matrix from top left to right bottom horizontally.
	Path could be like this:
	       a[0] -----> a[0, j]
		               |
					   |
					   |
					   \/
					   a[i, j]---->a[i, N]
					               |
								   |
								   \/
								   a[N]
	minSubArrayLen = min{j - i, while i, j belongs to the path}.
	*/

public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty())
			return 0;

		int i = 0;
		int j = 0;
		int n = nums.size();
		int minLen = INT_MAX;
		int step = 0;
		int bFromL = true; // false means from up.
		while (i < n && j < n ){
			if (bFromL){
				step += nums[j];
			} else{
				step -= nums[i - 1];
			}

			if (step >= s){
				minLen = std::min(minLen, j - i + 1);
				bFromL = false;
				++i;
			} else{
				bFromL = true;
				++j;
			}
		}

		return minLen == INT_MAX ? 0 : minLen;
	}

	// O(n^2), obviously bad idea.
	int minSubArrayLen_BF(int s, vector<int>& nums) {
		vector<int> d(nums.size(), 0);
		vector<int>& a = nums;
		int minLen = INT_MAX;
		//d[nums.size() - 1] = a[nums.size() - 1];
		for (int i = a.size() - 1; i >= 0; --i){
			d[i] = a[i];
			if (d[i] >= s)
				minLen = std::min(minLen, 1);
			for (int j = i + 1; j < a.size(); ++j){
				d[j] = d[i] + d[j];
				if (d[j] >= s)
					minLen = std::min(minLen, 1);
			}
		}

		return minLen == INT_MAX ? 0 : minLen;
	}
};


int main(int argc, char** argv){
	int A[] = { 5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
	vector<int> nums(A, A + sizeof(A) / sizeof(int));
	Solution s;
	cout << s.minSubArrayLen(15, nums) << endl;
	return 0;
}
