#include "common.h"

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> s;
		int minNum = nums[0];

		for (size_t i = 0; i < nums.size(); i++)
		{
			s.insert(nums[i]);
		}

		int ans = 0;
		while (!s.empty()) {
			int val = *s.begin(), k = val + 1, len = 1;
			s.erase(val);

			while (s.find(k) != s.end())
				++len, s.erase(k++);

			k = val - 1;
			while (s.find(k) != s.end())
				++len, s.erase(k--);

			ans = std::max(ans, len);
		}
		return ans;
	}
};

