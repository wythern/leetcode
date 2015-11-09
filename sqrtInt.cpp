#include "common.h"

class Solution {
public:
	int mySqrt(int n){
		/*We are using n itself as initial approximation
		This can definitely be improved */
		float x = n;
		float y = 1;
		float e = 0.000001; /* e decides the accuracy level*/
		while (x - y > e)
		{
			x = (x + y) / 2;
			y = n / x;
		}
		return (int)x;
	}

	int mySqrt_wrong(int x){
		if (x == 0)
			return 0;
		
		int r = 0;
		int i = 1;
		int k = 1000;

		if (x < 1000){
			for (; i < x; ++i)
			{
				if (i > x / i)
					return i - 1;
			}
		}

		while (k--){
			r = i;
			i = (i + x / i) / 2;
		}

		return r;
	}

	int mySqrt_fast(int x) {
		/*
		* X(k+1) = 1/2 * ( x(k) + n/x(k) );
		*/
		if (x == 0)
			return 0;

		float r = 0.0f;
		float nextR = 1.0f;
		int i = 10000;
		while (nextR != r && i--){
			r = nextR;
			nextR = (r + x / r) / 2.0f;
		}

		return (int)nextR;
	}
};

int main(int argc, char** argv){
	Solution s;
	cout << s.mySqrt(2147395599) << endl;
	return 0;
}
