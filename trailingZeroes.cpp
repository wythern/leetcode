#include "common.h"

class Solution {
public:
    int trailingZeroes(int n) {
		int nZ = 0;
		while (n > 0){
			nZ += n / 5;
			n /= 5;
		}
		return nZ;
    }

	uint64_t calcFactorial(int n){
		if (1 >= n)
			return 1;

		return n * calcFactorial(n - 1);
	}
};

int main(int argc, char** argv){
	Solution s;
	int n = 15;
	int z = s.trailingZeroes(n);
	cout << "trailing zeros = " << z << endl;

	cout << "Factorial of N = " << s.calcFactorial(n) << endl;
	return 0;
}
