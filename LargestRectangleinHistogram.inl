#include "common.h"

class Solution {
public:
	int largestRectangleArea_bruteforce(vector<int>& height) {
		int maxArea = INT_MIN;
		for (size_t i = 0; i < height.size(); i++){
			for (size_t j = i; j < height.size(); j++){
				int minLevel = INT_MAX;
				for (size_t k = i; k <= j; k++){
					if (minLevel > height[k])
						minLevel = height[k];
				}
				int area = minLevel * (j - i + 1);
				if (maxArea < area)
					maxArea = area;
			}
		}

		return maxArea;
	}

	int largestRectangleArea_DP(vector<int>& height) {
		vector<int> dpStatus(height.size(), INT_MAX);
		int maxArea = 0;
		int n = height.size();
		for (int i = 0; i < n; ++i){
			dpStatus[i] = height[i];
			if (maxArea < dpStatus[i])
				maxArea = dpStatus[i];

			for (int j = i - 1; j >= 0; --j){
				dpStatus[j] = std::min(dpStatus[j + 1], dpStatus[j]);
				int area = dpStatus[j] * (i - j + 1);
				if (maxArea < area)
					maxArea = area;
			}
		}

		return maxArea;
	}

	int largestRectangleArea(vector<int>& height) {
		if (height.empty())
			return 0;

		int maxArea = 0;
		int prevH = height[0];
		int currH = prevH;
		int i = 1;
		stack<int> idxStack;
		idxStack.push(0);
		int n = height.size();
		while (i < n){
			currH = height[i];
			if (currH >= prevH){
				idxStack.push(i);
			} else{
				while (!idxStack.empty() && height[idxStack.top()] > currH)
				{
					int pos = idxStack.top();
					int pastH = height[pos];
					idxStack.pop();
					int backSpan = idxStack.empty()? pos + 1 : pos - idxStack.top();

					int area1 = pastH * (i - 1 - pos + backSpan);
					int area2 = currH * (i - pos + 1);
					maxArea = std::max(maxArea, std::max(area1, area2));
				}
				idxStack.push(i);
			}
			++i;
			prevH = currH;
		}

		// process tail
		while (!idxStack.empty())
		{
			int pos = idxStack.top();
			int pastH = height[pos];
			idxStack.pop();
			int backSpan = idxStack.empty() ? pos + 1 : pos - idxStack.top();

			int area1 = pastH * (i - 1 - pos + backSpan);
			maxArea = std::max(maxArea, area1);
		}

		return maxArea;
	}


	int largestRectangleArea_reference(vector<int> &h) {
		stack<int> S;
		h.push_back(0);
		int sum = 0;
		for (int i = 0; i < h.size(); i++) {
			if (S.empty() || h[i] > h[S.top()]) S.push(i);
			else {
				int tmp = S.top();
				S.pop();
				sum = std::max(sum, h[tmp] * (S.empty() ? i : i - S.top() - 1));
				i--;

			}

		}
		return sum;

	}

};

int main(int argc, char** argv){
	Solution s;
	int A[] = { 1 };
	vector<int> vA(A, A + sizeof(A) / sizeof(int));
	//vA = generateRandomIntVector(1000, 1, 100);
	pfcout << s.largestRectangleArea(vA);

	pfcout << s.largestRectangleArea_reference(vA);

	//vA = generateRandomIntVector(512 << 4, 1, 1000);
	pfcout << s.largestRectangleArea_bruteforce(vA);
	return 0;
}