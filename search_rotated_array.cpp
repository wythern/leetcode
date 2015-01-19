#include "common.h"

class Solution {
public:
#define TARGET_IN_RANGE(a, b, t) ((a <= t) && (t <= b))
#define TARGET_IN_ROTATED_RANGE(a, b, t) ((a <= t) || (t <= b))
#define PIVOT_IN_RANGE(a, b, t) (a > b)

    int search(int A[], int n, int target) {
		if(NULL == A || 0 == n){
			return -1;
		}

        if(PIVOT_IN_RANGE(A[0], A[n-1], target)){
			search_rotated_array(A, 0, n, target);
		}else{
			binary_search_array(A, 0, n, target);			
		}
    }

	int search_rotated_array(int A[], int b, int e, int target) {
		if(b >= e - 1){
			return (A[b] == target) ? b : -1;
		}

		int m = b + (e - b)/2;
		if(A[m] != target){
			if (m > b && PIVOT_IN_RANGE(A[b], A[m - 1], target)) {
				if (TARGET_IN_ROTATED_RANGE(A[b], A[m - 1], target))
					return search_rotated_array(A, b, m, target);
				else if(TARGET_IN_RANGE(A[m + 1], A[e - 1], target))
					return binary_search_array(A, m + 1, e, target);
			} else if(m + 1 < e && PIVOT_IN_RANGE(A[m + 1], A[e - 1], target)){
				if (TARGET_IN_ROTATED_RANGE(A[m + 1], A[e - 1], target))
					return search_rotated_array(A, m + 1, e, target);
				if (TARGET_IN_RANGE(A[b], A[m - 1], target))
					return binary_search_array(A, b, m, target);
			} else { // m is the pivot
				if (m > b && TARGET_IN_RANGE(A[b], A[m - 1], target))
					return binary_search_array(A, b, m, target);
				if (m + 1 < e && TARGET_IN_RANGE(A[m + 1], A[e - 1], target))
					return binary_search_array(A, m + 1, e, target);
			}

			// all not found;
			return -1;
		}else
			return m;
	}

	int binary_search_array(int A[], int b, int e, int target){
		if(b >= e - 1){
			return (A[b] == target) ? b : -1;
		}

		int m = b + (e - b)/2;
		if (A[m] < target){
			return binary_search_array(A, m + 1, e, target);
		}else if (A[m] > target){
			return binary_search_array(A, b, m, target);
		}else
			return m;
	}
};

int main(int argc, char** argv){
	if(argc < 3){
		return -1;
	}

	Solution s;
#if 0
	int n = atoi(argv[1]);
	int *A = (int*)malloc(n*sizeof(int));

	struct timeval tv;
    gettimeofday(&tv,NULL);
	uint32_t seed = tv.tv_sec + tv.tv_usec;
    srand(seed);
	float r = double(rand())/RAND_MAX;
	cout << "r = " << r << endl;
	int pivot = (abs(n*r)) % n;

	cout << "p = " << pivot << endl;
	for(int i = 0; i < n; ++i){
		if(i < pivot)
			A[i] = n - pivot + i + 1;
		else
			A[i] = i - pivot + 1;
	}
	printArray<int>(A, n, "A");

	int target = atoi(argv[2]);
#else
	int A[] = {4, 5, 6, 7, 1, 2, 3};
	int n = 7;
	int target = atoi(argv[2]);
	printArray<int>(A, n, "A");
#endif
	cout << s.search(A, n, target) << endl;
	return 0;
}
