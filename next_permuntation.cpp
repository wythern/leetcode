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

	void traversalAllRange(vector<int> &num)
	{
		vector<int> vDigits(num);
		allRangeImpl(num, vDigits, vDigits.begin(), vDigits.end());
	}

	void allRangeImpl(vector<int>& num,
					  vector<int>& vDigits,
					  vector<int>::iterator pos,
					  vector<int>::iterator end)
	{
		if(pos == end){
			printContainer(vDigits, vDigits.size(), "vDigits");
			if(mNextPermuntation == num && mNextPermuntation < vDigits){
				mNextPermuntation = vDigits;
				printContainer(vDigits, vDigits.size(), "num");
			}else if(num < vDigits && vDigits < mNextPermuntation){
				mNextPermuntation = vDigits;
				printContainer(vDigits, vDigits.size(), "num");
			}
			return;
		}

		allRangeImpl(num, vDigits, pos+1, end);
		for(vector<int>::iterator it = pos + 1; it != end; ++it){
			swap(*it, *pos);
			allRangeImpl(vDigits, pos + 1, end, vAllRange);
			swap(*pos, *it);
		}
	}

private:
	vector<int> mNextPermuntation;
};

bool VectorLessThan(const vector<int>& a, const vector<int>& b)
{
	printf("a(%d), b(%d).\n", 0, 0);

	if(a.size() != b.size()){
		return (a.size() < b.size());
	}

	vector<int>::const_iterator itA = a.begin();
	vector<int>::const_iterator itB = b.begin();
	while(*itA != *itB && itA != a.end()){
		++itA;++itB;
	}

	return (itA == a.end()) ? false : *itA < *itB;
}

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
