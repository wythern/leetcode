#include "common.h"

class Solution {
private:
    int m_nCount;
    string m_strKthPermutation;
public:
    string getPermutation(int n, int k) {
        m_nCount = k;
        vector<int> num;
        for(int i = 0; i < n; ++i){
            num.push_back(i + 1);
        }

        if(m_nCount > 0){
            while(--m_nCount > 0){
                nextPermutation(num);
            }

            for(int i = 0; i < num.size(); ++i){
                m_strKthPermutation.push_back(num[i] + '0');
            }
        }

        return m_strKthPermutation;
    }

    void nextPermutation(vector<int> &num) {
        if (num.empty())
            return;

        vector<int>::reverse_iterator r = num.rbegin();
        for(vector<int>::reverse_iterator rIt = num.rbegin() + 1;
            rIt != num.rend();
            ++rIt){
            if( *rIt >= *r){
                r = rIt;
            }else{
                vector<int>::iterator it = num.end() - distance(num.rbegin(), rIt) - 1;
                sort(it + 1, num.end());
                swap(*upper_bound(it + 1, num.end(), *it), *it);
                return;
            }
        }

        sort(num.begin(), num.end());
        return;
    }

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
	int A[] = {1, 2, 3, 4};
	vector<int> vA(A, A+4);
	Solution s;
	vector<vector<int> > vR(s.permuteUnique(vA));
	//*
	for(int i = 0; i < vR.size(); ++i){
		printContainer<vector<int> >(vR[i], vR[i].size(), "");
	}
	//*/

    if(argc < 3){
        exit(0);
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    string strKthNum = s.getPermutation(n, k);
    cout << "Kth string = " << strKthNum << endl;
    printf("ks = %s.\n", strKthNum.c_str());
	return 0;
}
