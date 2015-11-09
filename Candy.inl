#include "common.h"


class Solution {
public:
	int candyImpl(vector<int>& ratings) {
		candyNum = vector<int>(ratings.size(), 0);
		if (ratings.empty())
			return 0;

		if (ratings.size() == 1)
			return 1;

		int baseCandy = 1;
		int currCandy = 1;
		int totalCandy = 0;
		candyNum[0] = 1;

		int i = 1;
		int prevRate = ratings[0];
		int currRate = ratings[1];
		bool bUpTrend = currRate >= prevRate;
		int beginPos = 0;
		int endPos = 1;
		int lv = 0;
		while (i < ratings.size()){
			currRate = ratings[i];
			if (bUpTrend && currRate >= prevRate){
				if (currRate != prevRate) ++lv;
				prevRate = currRate;
				++i;
				continue;
			} else if (!bUpTrend && currRate <= prevRate){
				if (currRate != prevRate) --lv;
				prevRate = currRate;
				++i;
				continue;
			} else if (bUpTrend && currRate < prevRate){
				int j = i - 1;
				endPos = i - 1;
				distributeCandy(ratings, beginPos, endPos, bUpTrend);

				while (j >= 0 && ratings[j] == prevRate){ --j; } // back to the start of the roof;
				beginPos = j + 1;
				bUpTrend = false;
				++i;
			} else if (!bUpTrend && currRate > prevRate){
				endPos = i - 1;
				if (lv > 0) {
					int j = beginPos;
					while (j + 1 < ratings.size() && ratings[j + 1] == ratings[j]){ ++j; } // fwd to the end of the roof;
					beginPos = j + 1;
				}
	
				distributeCandy(ratings, beginPos, endPos, bUpTrend);

				bUpTrend = true;
				lv = 0;
				beginPos = endPos;
				++i;
			}
		}

		// process tail.
		if (lv > 0 && !bUpTrend){
			int j = beginPos;
			while (j + 1 < ratings.size() && ratings[j + 1] == ratings[j]){ ++j; } // fwd to the end of the roof;
			beginPos = j + 1;
		}
		distributeCandy(ratings, beginPos, i - 1, bUpTrend);

		for (size_t i = 0; i < candyNum.size(); i++)
		{
			totalCandy += candyNum[i];
		}
		return totalCandy;
	}

	void distributeCandy(vector<int>& ratings, int startPos, int endPos, bool bUpTrend){
		int step = bUpTrend ? 1 : -1;
		if (!bUpTrend)
			std::swap(startPos, endPos);

		int base = 1;
		int prevRating = ratings[startPos];
		int currRating = prevRating;

		int i = startPos;
		while (i != endPos + step)
		{
			currRating = ratings[i];
			if (currRating != prevRating) ++base;
			prevRating = currRating;
			candyNum[i] = base;
			i += step;
		}
	}

	int candy(vector<int>& arr) {
		//int cand[100001] = { 0 };
		vector<int> cand = vector<int>(arr.size(), 0);
		int n = arr.size();
		for (int i = 1; i < n; i++)
		if (arr[i] > arr[i - 1]) cand[i] = cand[i - 1] + 1;
		for (int i = n - 2; i >= 0; i--)
		if (arr[i] > arr[i + 1]) cand[i] = std::max(cand[i], cand[i + 1] + 1);
		int sum = n;
		for (int i = 0; i < n; i++) sum += cand[i];
		return sum;
	}

public:
	vector<int> candyNum;
};

int main(int argc, char** argv){
	Solution s;
	int A[] = { 1, 2, 2};
	vector<int> vA(A, A + sizeof(A) / sizeof(int));
	pfcout << s.candy(vA);
	printContainer<vector<int>>(vA, vA.size());
	printContainer<vector<int>>(s.candyNum, s.candyNum.size());
	return 0;
}
