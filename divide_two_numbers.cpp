#include "common.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        int d = dividend;
        int r = divisor;
        int c = 1;
		if(0 == d)
			return 0;
		if(0 == r)
			return INT_MAX;
		
		int lr = 0;
		int lc = 0;
		if(d > 0 && r > 0){
			while (d - r >= 0){
				lr = r;
				lc = c;
				if(INT_MAX - c < c || INT_MAX - r < r)
					break;
				r += r;
			    c += c;
			}

			if(0 == lc)
				return lc;

			d -= lr;
			r = divisor;
			int sublc = divide(d, r);
			if(INT_MAX - lc < sublc)
				return INT_MAX;

			lc += sublc;
		}else if(d < 0 && r < 0){
			while (d - r <= 0){
				lr = r;
				lc = c;
				if(INT_MIN - r > r || INT_MAX - c < c)
					break;
				r += r;
			    c += c;
			}

			if(0 == lc)
				return lc;

			d -= lr;
			r = divisor;
			int sublc = divide(d, r);
			if(INT_MAX - lc < sublc)
				return INT_MAX;

			lc += sublc;
		}else if(d > 0 && r < 0){
			c = -1;
			while (d + r >= 0){
				lr = r;
				lc = c;
				if(INT_MIN - r > r || INT_MIN - c > c)
					break;
				r += r;
			    c += c;
			}

			if(0 == lc)
				return lc;

			d += lr;
			r = divisor;
			int sublc = divide(d, r);
			if(INT_MIN - lc > sublc)
				return INT_MAX;

			lc += sublc;
		}else{ //(d < 0 && r > 0){
			c = -1;
			while (d + r <= 0){
				lr = r;
				lc = c;
				if(INT_MAX - r < r || INT_MIN - c > c)
					break;
			    c += c;
				r += r;
			}

			if(0 == lc)
				return lc;

			d += lr;
			r = divisor;
			int sublc = divide(d, r);
			if(INT_MIN - lc > sublc)
				return INT_MAX;
			lc += sublc;
		}

		return lc;
    }

};

int main(int argc, char** argv){
	int a;
	int b;
	if(argc < 3){
		a = 5;
		b = 3;
	}else{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
	}

	Solution s;
	cout << a << "/" << b << "=" << s.divide(a, b) << endl;
	return 0;
}
