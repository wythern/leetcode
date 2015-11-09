#include "common.h"

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k < 1 || k > nums.size())
			return vector<int>();

		vector<int> dMax(nums.size(), INT_MIN);
		for (int i = 0; i < nums.size(); ++i){
			for (int j = i; j < i + k && j < nums.size(); ++j)
				dMax[j] = std::max(dMax[j], nums[i]);
		}

		vector<int> maxWindow;
		for (int i = k - 1; i < nums.size(); ++i){
			maxWindow.push_back(dMax[i]);
		}

		return maxWindow;
	}

	vector<int> maxSlidingWindowImpl(vector<int>& nums, int k) {
		std::deque<int> q;
		vector<int> r;
		for (int i = 0; i<nums.size(); ++i) {
			if (q.empty()) q.push_back(i);
			else if (nums[q.front()] <= nums[i]) {
				q.clear(); q.push_back(i);
			} else {
				if (q.front() + k <= i) q.pop_front();
				while (!q.empty() && nums[q.back()] <= nums[i]) {
					q.pop_back();
				}
				q.push_back(i);
			}
			if (i >= (k - 1)) {
				r.push_back(nums[q.front()]);
			}
		}
		return r;
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[] = { 10, 3, -1, -3, 5, 3, 6, 7, 1};
	generateRandomIntVector(1000, -100, 100);
	vector<int> vA(A, A + sizeof(A) / sizeof(int));
	vA = generateRandomIntVector(500000, -100, 100);

	//printContainer<vector<int>>(vA, vA.size());
	pfcout << "-----------------------";
	pfcout << s.maxSlidingWindow(vA, 3).size();
	pfcout << s.maxSlidingWindowImpl(vA, 3).size();

	
	//printContainer<vector<int>>(vA, vA.size());
	return 0;
}