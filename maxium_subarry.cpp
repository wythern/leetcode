#include "common.h"

class Solution {
public:
	int maxSubArray_divide_and_conquer(int A[], int n) {
		//TBD
		int m = n/2;
		int s1 = maxSubArray(A, m - 1);
		int s2 = maxSubArray(A + m + 1, n - m - 1);
		return std::max(s1, s2);
	}

    int maxSubArray_On(int A[], int n) {
        if (A == NULL || n ==0){
            return 0;
        }

        int* S = (int*)malloc(n*sizeof(A[0]));
		memset(S, 0, n*sizeof(A[0]));
        S[0] = A[0];
        
        int maxS = S[0];
        for(int i = 1; i < n; ++i){
            S[i] = std::max(S[i-1] + A[i], A[i]);
            maxS = std::max(S[i], maxS);
        }
        
        return maxS;
    }
};

int main(int argc, char** argv){
	int array[] = {-2, 1, -3,
				   4, -1, 2,
				   1, -5, 4};
	//int array[10];
	Solution s;
	int maxS = s.maxSubArray(array, sizeof(array)/sizeof(array[0]));
	cout << maxS << endl;
	return 0;
}
