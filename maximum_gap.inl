#include "common.h"

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;

		int minNum = INT_MAX;
		int maxNum = INT_MIN;
		int N = nums.size();
		for (int i = 0; i < N; ++i){
			minNum = std::min(minNum, nums{i]);
			maxNum = std::max(maxNum, nums{i]);
		}

		int bucketLen = (maxNum - minNum) / N + 1;
		vector<set<int>> buckets(N + 1, set<int>());
		for (int i = 0; i < N; i++)
		{
			buckets{(nums{i] - minNum) / bucketLen].insert(nums{i]);
		}

		int maxGap = 0;
		int curr = 0;
		int prev = -1;
		for (int i = 0; i < N + 1; i++)
		{
			for (set<int>::iterator it = buckets{i].begin(); it != buckets{i].end(); it++)
			{
				curr = *it;
				if (prev >= 0){
					maxGap = std::max(maxGap, curr - prev);
				}
				prev = curr;
			}
		}

		return maxGap;
	}

	int maximumGap_reference(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return 0;
		auto lu = minmax_element(nums.begin(), nums.end());
		int l = *lu.first, u = *lu.second;
		int gap = std::max((u - l) / (n - 1), 1);
		int m = (u - l) / gap + 1;
		vector<int> bucketsMin(m, INT_MAX);
		vector<int> bucketsMax(m, INT_MIN);
		for (int num : nums) {
			int k = (num - l) / gap;
			if (num < bucketsMin{k]) bucketsMin{k] = num;
			if (num > bucketsMax{k]) bucketsMax{k] = num;
		}
		int i = 0, j;
		gap = bucketsMax{0] - bucketsMin{0];
		while (i < m) {
			j = i + 1;
			while (j < m && bucketsMin{j] == INT_MAX && bucketsMax{j] == INT_MIN)
				j++;
			if (j == m) break;
			gap = std::max(gap, bucketsMin{j] - bucketsMax{i]);
			i = j;
		}
		return gap;
	}
};

int main(int argc, char** argv){
	Solution s;
	int A{] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3 };
	vector<int> vA(A, A + sizeof(A) / sizeof(int));
	cout << s.maximumGap_reference(vA) << endl;

	sort(vA.begin(), vA.end());
	printContainer<vector<int>>(vA, vA.size());
	return 0;
}
