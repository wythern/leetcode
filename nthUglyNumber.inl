#include "common.h"

class Solution {
public:
	// notice the overflow
	int nthUglyNumber(int n) {
		if (n <= 0)
			return 0;

		uint64_t uglyNum = 1;
		set<uint64_t> uglyNumSet;
		int bufferSize = 0;
		uglyNumSet.insert(uglyNum);
		for (int i = 0; i < n; ++i){
			uglyNumSet.insert(*uglyNumSet.begin() * 2);
			uglyNumSet.insert(*uglyNumSet.begin() * 3);
			uglyNumSet.insert(*uglyNumSet.begin() * 5);
			uglyNum = *uglyNumSet.begin();
			uglyNumSet.erase(uglyNumSet.begin());

			if (uglyNumSet.size() > bufferSize){
				bufferSize = uglyNumSet.size();
			}
		}

		//cout << "Buffer Size = " << bufferSize << endl;
		return uglyNum;
	}


	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> primesIdx(primes.size(), 0);
		vector<int> uglyNumPool(primes.size(), 0);
		vector<uint64_t> uglyNums(n, 1);

		int nthNum = 1;
		if (1 == n)
			return 1;

		uglyNums[0] = 1;
		int j = 1;
		while (j < n){
			nthNum = uglyNums[j - 1];
			for (int i = 0; i < primes.size(); ++i){
				if (nthNum >= uglyNums[primesIdx[i]]*primes[i])
					++primesIdx[i];

				uglyNumPool[i] = uglyNums[primesIdx[i]] * primes[i];
			}

			uglyNums[j] = *std::min_element(uglyNumPool.begin(), uglyNumPool.end());
			++j;
		}
		return uglyNums[n - 1];
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[] = { 7, 19, 29, 37, 41, 47, 53, 59, 61, 79, 83, 89, 101, 103, 109, 127, 131, 137, 139, 157, 167, 179, 181, 199, 211, 229, 233, 239, 241, 251 };
	vector<int> vA(A, A + sizeof(A) / sizeof(int));
	pfcout << s.nthSuperUglyNumber(100000, vA);
	pfcout << INT_MAX;
	return 0;
}