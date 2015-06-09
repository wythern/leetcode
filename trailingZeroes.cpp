#include "common.h"

class Solution {
public:
    int trailingZeroes(int n) {
        return trailingZerosRange(1, n);
    }
    
    int trailingZerosRange(int l, int r){
        if(l > r)
            return 0;

        if(l == r){
            int k = 0;
            while(!(l%10)){
                l /= 10;
                k++;
            }
            return k;
        }
        
        int s = (r - l)/2;
        int m = trailingZerosRange(l, l + s);
        int n = trailingZerosRange(l + s + 1, r);
        return m+n;
    }
};

int main(int argc, char** argv){
	Solution s;
	int n = s.trailingZeroes(1808548329);
	cout << "Rect area = " << n << endl;
	return 0;
}
