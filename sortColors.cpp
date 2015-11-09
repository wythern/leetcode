#include "common.h"

class Solution {
public:
	void sortColorsQsort(int A[], int n) {
		if(n <= 1)
			return;

		int k = select(A, n);
		sortColorsQsort(A, k);
		sortColorsQsort(A + k + 1, n - k - 1);
	}

	int select(int A[], int n){
		if(n <= 0)
			return 0;

		int i = 1;
		int lo = 0;
		while(i < n){
			if(A[i] < A[0]){
				lo = i;
				++i;
			}else{
				int j = i + 1;
				while(j < n && A[j] > A[0])
					++j;

				if(j < n){
					std::swap(A[i], A[j]);
					lo = i;
					++i;
				}else{
					i = n;
				}
			}
		}

		std::swap(A[0], A[lo]);
		return lo;
	}

    void sortColorsTwoPass(int A[], int n) {
		int c[3] = {0, 0, 0};
        for(int i = 0; i < n; ++i){
			c[A[i]]++;
		}

		for(int i = 0; i < n; ++i){
			if(i < c[0])
				A[i] = 0;
			else if(i >= c[0] && i < c[0] + c[1])
				A[i] = 1;
			else
				A[i] = 2;
		}
    }
};

int main(int argc, char** argv){

	Solution s;
	//int array[] ={0,1,2,1,2,1,2,1,0,1,0,2,2,1,2,1,0,0,0};
	int array[] ={2,0};
	int n = sizeof(array)/sizeof(int);
	printArray<int>(array, n, "array");
	s.sortColorsQsort(array, n);
	printArray<int>(array, n, "array sorted");
	return 0;
}
