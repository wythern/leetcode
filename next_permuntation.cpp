#include "common.h"

class Solution {
public:
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

    void nextPermutation_allrange(vector<int> &num) {
		vector<vector<int> > vAllRange(allRange(num));
		sort(vAllRange.begin(), vAllRange.end());
		vector<vector<int> >::iterator it = std::upper_bound(vAllRange.begin(), vAllRange.end(), num);
#if 0
        for(vector<vector<int> >::iterator it = vAllRange.begin();
            it != vAllRange.end();
            ++it){
            printContainer<vector<int> >(*it, it->size(), "AllRange");
        }
#endif		
		if(vAllRange.end() == it)
			num = *vAllRange.begin();
		else
			num = *it;
    }

	vector<vector<int> > allRange(const vector<int> &num)
	{
		vector<int> vDigits(num);
		vector<vector<int> > vAllRange;
		allRangeImpl(vDigits, vDigits.begin(), vDigits.end(), vAllRange);
		return vAllRange;
	}

	void allRangeImpl(vector<int>& vDigits,
					  vector<int>::iterator pos,
					  vector<int>::iterator end,
					  vector<vector<int> >& vAllRange)
	{
		if(pos == end){
			vAllRange.push_back(vDigits);
			//printContainer<vector<int> >(vDigits, vDigits.size(), "AllRange");
			return;
		}

		allRangeImpl(vDigits, pos+1, end, vAllRange);
		for(vector<int>::iterator it = pos + 1; it != end; ++it){
			swap(*it, *pos);
			allRangeImpl(vDigits, pos + 1, end, vAllRange);
			swap(*pos, *it);
		}
	}
};

int main(int argc, char** argv){
	if(argc < 2){
		printf("%s pattern.\n", argv[0]);
		return 0;
	}

	Solution s;
	string strPattern(argv[1]);
	vector<int> num;
	for(int i = 0; i < strPattern.size(); ++i){
		char ch = strPattern[i];
		num.push_back(ch - '0');
	}
	printContainer<vector<int> >(num, num.size(), "Input");

	vector<int> ref(num);
	s.nextPermutation_allrange(ref);

	s.nextPermutation(num);
	//printContainer<vector<int> >(num, num.size(), "Result");
    if(num != ref){
        printContainer<vector<int> >(ref, num.size(), "Result_REF");
        printContainer<vector<int> >(num, num.size(), "Result_NUM");
    }else
        printContainer<vector<int> >(num, num.size(), "Result_OUTPUT");

	return 0;
}
