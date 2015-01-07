#include "common.h"

class Solution {
public:
    void nextPermutation(vector<int> &num) {
		vector<vector<int> > vAllRange(allRange(num));
		sort(vAllRange.begin(), vAllRange.end());
		vector<vector<int> >::iterator it = std::upper_bound(vAllRange.begin(), vAllRange.end(), num);
		
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
			allRangeImpl(vDigits, it, end, vAllRange);
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
		num.push_back(atoi(&ch));
	}

	s.nextPermutation(num);
	printContainer<vector<int> >(num, num.size(), "Result");
	return 0;
}
