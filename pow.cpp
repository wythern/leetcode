#include "common.h"

class Solution {
public:
    double pow(double x, int n) {
        if(n >= 0){
            return pow_positive(x, n);
        }else
            return 1/pow_positive(x, -n);
    }
    
    double pow_positive(double x, int n){
        if(n == 0)
            return 1.0f;
        if(n == 1)
            return x;

        double t = pow(x, n/2);
        if(n%2){
            return t*t*x;
        }else{
            return t*t;
        }
    }
};


int main(int argc, char** argv){
	Solution s;
	cout << s.pow(2.0, 10) << endl;
	return 0;
}
