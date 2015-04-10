#include "common.h"
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
		int i = 0;
		int j = 0;
		memmove(A + n, A, m*sizeof(int));
		printArray(A, 10, "A");		

		int *pA = A;
		while(i < m || j < n){
			if((i < m && A[n + i] < B[j]) || j == n){
				*pA = A[n + i];
				++i;
				pA++;
			}else if((j < n && A[n + i] >= B[j]) || i == m){
				*pA = B[j];
				++j;
				pA++;
			}
		}
    }
};

int main(int argc, char** argv){
	int A[] = {1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0};
	int B[] = {2, 9, 15, 24, 100};

	Solution s;
	s.merge(A, 3, B, 5);
	printArray(A, 10, "A");
	return 0;
}
