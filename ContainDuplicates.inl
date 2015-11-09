#include "common.h"

class Solution {
public:


	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		set<int> hashMap;
		for (int i = 0; i <= k && i < nums.size(); ++i){
			if (hashMap.find(nums[i]) != hashMap.end())
				return true;
			hashMap.insert(nums[i]);
		}

		for (int i = k + 1; i < nums.size(); ++i){
			hashMap.erase(nums[i - k - 1]);
			if (hashMap.find(nums[i]) != hashMap.end())
				return true;
			hashMap.insert(nums[i]);
		}

		return false;
	}
};