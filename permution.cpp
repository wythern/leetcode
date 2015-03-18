#include "common.h"

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > vResults;
		permuteImpl_Unique(num, num.begin(), num.end(), vResults);
		return vResults;
    }

	void permuteImpl(vector<int>& num,
					 vector<int>::iterator beginPos,
					 vector<int>::iterator endPos,
					 vector<vector<int> >& vResults){
		if(endPos <= beginPos){
			vResults.push_back(num);
			return;
		}

		permuteImpl(num, beginPos + 1, endPos, vResults);
		for(vector<int>::iterator it = beginPos + 1;
			it != endPos;
			++it){
			std::swap(*it, *beginPos);
			permuteImpl(num, beginPos + 1, endPos, vResults);
			std::swap(*it, *beginPos);
		}
	}

	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int> > vResults;
		permuteImpl_Unique(num, num.begin(), num.end(), vResults);
		return vResults;
    }


	void permuteImpl_Unique(vector<int>& num,
							vector<int>::iterator beginPos,
							vector<int>::iterator endPos,
							vector<vector<int> >& vResults){
		if(endPos <= beginPos){
			//printContainer<vector<int> >(num, num.size(), "");
			vResults.push_back(num);
			return;
		}

		set<int> sUnique;
		permuteImpl_Unique(num, beginPos + 1, endPos, vResults);
		sUnique.insert(*beginPos);
		for(vector<int>::iterator it = beginPos + 1;
			it != endPos;
			++it){
			if(sUnique.insert(*it).second){
				std::swap(*it, *beginPos);
				permuteImpl_Unique(num, beginPos + 1, endPos, vResults);
				std::swap(*it, *beginPos);
			}
		}
	}
	
};

int main(int argc, char** argv){
	int A[] = {1, 1, 2, 2};
	vector<int> vA(A, A+4);
	Solution s;
	vector<vector<int> > vR(s.permuteUnique(vA));
	//*
	for(int i = 0; i < vR.size(); ++i){
		printContainer<vector<int> >(vR[i], vR[i].size(), "");
	}
	//*/
	return 0;
}
