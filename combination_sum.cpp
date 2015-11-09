#include "common.h"

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		set<vector<int> > s = combinationSumImpl(candidates, target);
		vector<vector<int> > v(s.begin(), s.end());
		return v;
	}

    set<vector<int> > combinationSumImpl(vector<int> &candidates, int target) {
		set<vector<int> > setOutput;
		for(int i = 0; i < candidates.size(); ++i){
			set<vector<int> > s;
			if(target == candidates[i]){
				vector<int> r(1, target);
				setOutput.insert(r);
			}else{
				int rest = target - candidates[i];
				if(rest > 0){
					s = combinationSumImpl(candidates, rest);
					vector<vector<int> > v(s.begin(), s.end());
					for(int j = 0; j < v.size(); ++j){
						v[j].push_back(candidates[i]);
						sort(v[j].begin(), v[j].end());
					}
					setOutput.insert(v.begin(), v.end());
				}
			}
		}

		return setOutput;
    }


	vector<vector<int>> combinationSum3(int k, int n) {
		int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		vector<vector<int>> vCombination;
		vector<int> combination;

		combinationSum3Impl(k, n, 0, A, combination, vCombination);
		return vCombination;
	}

	void combinationSum3Impl(int k, int n, int i, int A[], vector<int>& combination, vector<vector<int>>& vCombination){
		if (k == 0){
			if (n == 0)
				vCombination.push_back(combination);
			return;
		}

		for (int j = i; A[j] <= n; ++j){
			combination.push_back(A[j]);
			combinationSum3Impl(k - 1, n - A[j], j + 1, A, combination, vCombination);
			combination.pop_back();
		}
	}
};

int main(int argc, char** argv){
	int A[] = {2, 3, 6, 7};
	int t = 7;
	Solution s;
	vector<int> vInput(A, A+4);
	vector<vector<int> > v = s.combinationSum(vInput, 7);
	for(int i = 0; i < v.size(); ++i)
		printContainer<vector<int> > (v[i], v[i].size(), "v");

	v = s.combinationSum3(3, 7);
	for (int i = 0; i < v.size(); ++i)
		printContainer<vector<int> >(v[i], v[i].size(), "v");
	return 0;
}
