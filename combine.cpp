#include "common.h"

class Solution {
public:
	vector<vector<int> > subsets(vector<int>& S){
		vector<vector<int> > vResult;
		vector<int> combination;
		sort(S.begin(), S.end());
		for(int i = 0; i <= S.size(); ++i){
			m_vCombination.clear();
			combination.clear();
			combineImpl(combination, S, S.begin(), i);
			vResult.insert(vResult.end(), m_vCombination.begin(), m_vCombination.end());
		}
		
		return vResult;
	}
	
    vector<vector<int> > combine(int n, int k) {
		vector<int> combination;
		vector<int> vNums;
		for(int i = 0; i < n; ++i)
			vNums.push_back(i + 1);

		m_vCombination.clear();
		combineImpl(combination, vNums, vNums.begin(), k);
		return m_vCombination;
    }

	void combineImpl(vector<int>& combination,
					 vector<int>& vNums,
					 vector<int>::iterator itNums,
					 int k){
		if(k == 0){
			m_vCombination.push_back(combination);
			return;
		}

		if(itNums != vNums.end()){
			combination.push_back(*itNums);
			combineImpl(combination, vNums, itNums+1, k-1);
			combination.pop_back();
			combineImpl(combination, vNums, itNums+1, k);
		}
	}

private:
	vector<vector<int> > m_vCombination;	
	
};

int main(int argc, char** argv){
	if(argc < 3)
		exit(0);

	Solution s;
	vector<vector<int> > grid(s.combine(atoi(argv[1]), atoi(argv[2])));
	for(int i = 0; i < grid.size(); ++i)
		printContainer<vector<int> >(grid[i], grid[i].size(), "Result");

	vector<int> vNums;
	for(int i = 0; i < atoi(argv[1]); ++i)
		vNums.push_back(i + 1);

	grid = s.subsets(vNums);
	for(int i = 0; i < grid.size(); ++i)
		printContainer<vector<int> >(grid[i], grid[i].size(), "Result II");

	return 0;
}
