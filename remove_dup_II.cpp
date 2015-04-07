#include "common.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int *pDst = A;
		int *pSrc = A;
		int prev = A[0] - 1;
		int curr = A[0] - 1;
		int k = -1;
		int l = 0;
        for(int i = 0; i < n; ++i){
			curr = A[i];
			if(curr != prev){
				k = 2;
			}
			prev = curr;

			--k;
			if(k >= 0){
				*pDst++ = *pSrc;
				l++;
			}else{
				k = -1; // avoid exceeding.
			}

			pSrc++;
		}
		return l;
    }
};

int main(int argc, char** argv){
	int p[] = {1,2,3,4,4,4};
	Solution s;
	int n = s.removeDuplicates(p, sizeof(p)/sizeof(int));
	printArray<int>(p, n, "P");
	return 0;
}
