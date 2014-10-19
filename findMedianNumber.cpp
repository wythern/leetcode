#include "common.h"

using namespace std;

//#define NEED_DEBUG_PRINT

#ifdef NEED_DEBUG_PRINT
#define DEBUG_PRINT printf
#else
#define DEBUG_PRINT
#endif

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if((m+n)%2){
			return findMedianSortedArrays_legacy(A, m, B, n, (m+n-1)/2);
		}else{
			double a = findMedianSortedArrays_legacy(A, m, B, n, (m+n-1)/2);
			double b = findMedianSortedArrays_legacy(A, m, B, n, (m+n)/2);
			//DEBUG_PRINT("a = %f, b = %f.\n", a, b);
			return (a+b)/2.0f;
		}
	}

	double findMedianSortedArrays_legacy(int A[], int m, int B[], int n, int targetIdx) {
		//int targetIdx = (m+n-1)/2;
		int idxBegin = -1;
		int idxEnd = -1;
		std::vector<int> vA(A, A+m);
		std::vector<int> vB(B, B+n);
		int nLenth = n;
		int left = 0;
		int right = n - 1;
		int nPos = (nLenth - 1)>>1;

		if(m == 0 && n != 0){
			return B[targetIdx];
		}else if(m != 0 && n == 0){
			return A[targetIdx];
		}

		// pinpoint B
		while((nLenth > 0) && (nPos >= 0)){
			//using middle b to clamp a
			int nMedianB = B[nPos];
			idxBegin = std::distance(vA.begin(), std::lower_bound(vA.begin(), vA.end(), nMedianB)) + nPos;
			idxEnd = std::distance(vA.begin(), std::upper_bound(vA.begin(), vA.end(), nMedianB)) + nPos;
			//DEBUG_PRINT("B:: nLength(%d), nPos(%d), idx[%d, %d).\n", nLenth, nPos, idxBegin, idxEnd);

			if(idxBegin > targetIdx && idxEnd > targetIdx){
				right = nPos - 1;
			}else if(idxBegin < targetIdx && idxEnd < targetIdx){
				left = nPos + 1;
			}else{
				return nMedianB;
			}

			nLenth = right - left + 1;
			nPos = left + ((nLenth - 1)>>1);
		}

		// pinpoint A
		nLenth = m;
		left = 0;
		right = m - 1;
		nPos = (nLenth - 1)>>1;
		while((nLenth > 0) && (nPos >= 0)){
			//using middle b to clamp a
			int nMedianA = A[nPos];
			idxBegin = std::distance(vB.begin(), std::lower_bound(vB.begin(), vB.end(), nMedianA)) + nPos;
			idxEnd = std::distance(vB.begin(), std::upper_bound(vB.begin(), vB.end(), nMedianA)) + nPos;
			//DEBUG_PRINT("A:: nLength(%d), nPos(%d), idx[%d, %d).\n", nLenth, nPos, idxBegin, idxEnd);

			if(idxBegin > targetIdx && idxEnd > targetIdx){
				right = nPos - 1;
			}else if(idxBegin < targetIdx && idxEnd < targetIdx){
				left = nPos + 1;
			}else{
				return nMedianA;
			}

			nLenth = right - left + 1;
			nPos = left + ((nLenth - 1)>>1);
		}

		//DEBUG_PRINT("ERROR! should not be here forever.\n");
		return 0;
	}

private:
};

void Test(int A[], int m, int B[], int n, double target)
{
   Solution s;
   double nMedian = s.findMedianSortedArrays(A, m, B, n);
   if(nMedian != target){
	   printArray(A, m, "A");
	   printArray(B, n, "B");
	   printf("TEST FAILED! mid(%f) != target(%f).\n", nMedian, target);
	   assert(0);
   }else{
	   printf("TEST PASSED!\n");
   }
}
int A[10];
int B[10];

int main()
{
   cout << "Hello World" << endl;

#if 1
   A[0] = 2;
   B[0] = 2;  
   Test(A, 1, B, 0, 2);
   
   A[0] = 2;
   B[0] = 2;  
   Test(A, 1, B, 1, 2);

   A[0] = 2;
   B[0] = 3;
   Test(A, 1, B, 1, 2.5);

   A[0] = 1;
   B[0] = 2;B[1] = 3;
   Test(A, 0, B, 2, 2.5);

   A[0] = 1;A[1] = 2;
   B[0] = 2;B[1] = 3;
   Test(A, 2, B, 2, 2);

   A[0] = 1;A[1] = 2;A[2] = 3;
   B[0] = 4;B[1] = 5;
   Test(A, 3, B, 2, 3);
   
   A[0] = 1;A[1] = 3;A[2] = 5;
   B[0] = 2;B[1] = 4;
   Test(A, 3, B, 2, 3);

   A[0] = 1;A[1] = 3;A[2] = 5;
   B[0] = 2;B[1] = 4;B[2] = 4;
   Test(A, 3, B, 3, 3.5);

   A[0] = 1;A[1] = 4;A[2] = 5;
   B[0] = 2;B[1] = 4;B[2] = 4;
   Test(A, 3, B, 3, 4);

   A[0] = 5;A[1] = 6;
   B[0] = 1;B[1] = 2;B[2] = 3;B[3] = 4;
   Test(A, 2, B, 4, 3.5);

#else
   A[0] = 1;A[1] = 3;A[2] = 5;
   B[0] = 2;B[1] = 4;
   Solution s;
   std::cout << s.findMedianSortedArrays_legacy(A, 3, B, 2, 2) << std::endl;
#endif
   return 0;
}

