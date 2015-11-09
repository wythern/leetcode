#include "common.h"

class Solution {
public:
    int climbStairs(int n) {
        if(0 == n)
            return 0;

        int *s = (int*)malloc(n*sizeof(int));
        s[0] = 1;
        s[1] = 2;
        for(int i = 2; i < n; ++i)
            s[i] = s[i-1] + s[i-2];
        return s[n-1];
    }
};

int main(int argc, char** argv){
	Solution s;
	s.climbStairs(10);
	return 0;
}
