#include "common.h"

class Solution {
public:
    void nextPermutation(vector<int> &num) {
		if(num.empty())
			return;

		mNextPermuntation = num;
		traversalAllRange(num);
		swap(num, mNextPermuntation);
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
			allRangeImpl(num, vDigits, it, end);
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
		num.push_back(atoi(&ch));
	}

	s.nextPermutation(num);
	printContainer<vector<int> >(num, num.size(), "Result");
	return 0;
}
