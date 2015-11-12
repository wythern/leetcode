#include "common.h"

class Solution {
public:
	int countDigitOne_BF(int n) {
		if (n<1)return 0;
		long ones = 0;
		for (long m = 1; m <= n; m *= 10){
			long a = n / m;
			long b = n%m;
			ones += (a + 8) / 10 * m + (a % 10 == 1)*(b + 1);
		}
		return ones;
	}

	int countDigitOne(int n, int prevCnt){
	}

	int countDigitOne(int n){
		if (n == 0)
			return 0;

		int len = 0;
		int num = n;
		while (num){
			num /= 10;
			len++;
		}

		int cntDigitOne = 0;
		num = n;
		for (size_t i = 0; i < len; i++)
		{
			cntDigitOne += countDigitOneForDigit(num, n%10, i);
			n /= 10;
		}

		return cntDigitOne;
	}

	int countDigitOneForDigit(int num, int digit, int d){
		int powerOfTen = pow(10, d);
		int powerOfTenNext = pow(10, d + 1);
		int roundDownNext = num - (num % powerOfTenNext);
		int roundUpNext = num + powerOfTenNext - (num % powerOfTenNext);
		int right = num % powerOfTen;

		if (digit == 1){
			return roundDownNext / 10 + right + 1;
		} else if(digit < 1) {
			return roundDownNext / 10;
		} else { // digit > 1
			return roundUpNext / 10;
		}
	}

};

int main(int argc, char** argv){
	Solution s;
	for (size_t i = 0; i < 114; i++)
	{
		pfcout << s.countDigitOne(i);
		pfcout << s.countDigitOne_BF(i);
		cout << "-------------------------------" << endl;
	}
	return 0;
}