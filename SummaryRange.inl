#include "common.h"

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> vStr;
		if (nums.empty())
			return vStr;

		int curr = nums[0];
		int start = curr;
		for (int i = 0; i < nums.size(); ++i){
			curr = nums[i];
			if (i + 1 < nums.size() && nums[i + 1] != curr + 1){
				ostringstream oss;
				if (start != curr)
					oss << start << "->";
				oss << curr;
				vStr.push_back(oss.str());
				start = nums[i + 1];
			}
		}

		ostringstream oss;
		if (start != curr)
			oss << start << "->";
		oss << curr;
		vStr.push_back(oss.str());

		return vStr;
	}
};
