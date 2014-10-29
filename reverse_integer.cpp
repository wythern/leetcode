#include "common.h"

class Solution {
public:
    int reverse(int x) {
		int n = abs(x);
		int c = (x < 0) ? -1 : 1;
		int r = 0;
        while(n != 0){
			r = r*10 + n%10;
			n /= 10;
		}
		r *= c;
		return r;
    }
};

int main(int argc, char** argv)
{
	Solution s;
	int n = atoi(argv[1]);
	std::cout << s.reverse(n) << std::endl;
	return 0;
}
