#include "common.h"

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int targetIdx = (m+n-1)/2;
		int idxBegin = -1;
		int idxEnd = -1;
		std::vector<int> vA(A, A+m);
		std::vector<int> vB(B, B+n);
		int nLenth = n;
		int nPos = (nLenth - 1)>>1;

		if(m == 0 && n != 0){
			return B[(n-1)/2];
		}else if(m != 0 && n == 0){
			return A[(m-1)/2];
		}

		// pinpoint B
		while((nLenth > 0) && (nPos >= 0)){
			//using middle b to clamp a
			int nMedianB = B[nPos];
			idxBegin = std::distance(vA.begin(), std::lower_bound(vA.begin(), vA.end(), nMedianB)) + nPos;
			idxEnd = std::distance(vA.begin(), std::upper_bound(vA.begin(), vA.end(), nMedianB)) + nPos;
			//printf("B:: nLength(%d), nPos(%d), idx[%d, %d).\n", nLenth, nPos, idxBegin, idxEnd);

			if(idxBegin > targetIdx && idxEnd > targetIdx){
				nLenth = nPos;
				nPos = (nLenth - 1)>>1;
			}else if(idxBegin < targetIdx && idxEnd < targetIdx){
				nLenth -= nPos + 1;
				nPos++; // reset the start position.
				nPos += (nLenth - 1)>>1;
			}else{
				return nMedianB;
			}
		}

		// pinpoint A
		nLenth = m;
		nPos = (nLenth - 1)>>1;
		while((nLenth > 0) && (nPos >= 0)){
			//using middle b to clamp a
			int nMedianA = A[nPos];
			idxBegin = std::distance(vB.begin(), std::lower_bound(vB.begin(), vB.end(), nMedianA)) + nPos;
			idxEnd = std::distance(vB.begin(), std::upper_bound(vB.begin(), vB.end(), nMedianA)) + nPos;
			//printf("A:: nLength(%d), nPos(%d), idx[%d, %d).\n", nLenth, nPos, idxBegin, idxEnd);

			if(idxBegin > targetIdx && idxEnd > targetIdx){
				nLenth = nPos;
				nPos = (nLenth - 1)>>1;
			}else if(idxBegin < targetIdx && idxEnd < targetIdx){
				nLenth -= nPos + 1;
				nPos++; // reset the start postion.
				nPos += (nLenth - 1)>>1;
			}else{
				return nMedianA;
			}
		}

		//printf("ERROR! should not be here forever.\n");
		return 0;
	}

private:
};

void Test(int A[], int m, int B[], int n, int target)
{
   Solution s;
   int nMedian = s.findMedianSortedArrays(A, m, B, n);
   if(nMedian != target){
	   printArray(A, m);
	   printArray(B, n);
	   printf("TEST FAILED! mid(%d) != target(%d).\n", nMedian, target);
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

   A[0] = 2;
   B[0] = 2;  
   Test(A, 1, B, 0, 2);
   
   A[0] = 2;
   B[0] = 2;  
   Test(A, 1, B, 1, 2);
   
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
   Test(A, 3, B, 3, 3);

   A[0] = 1;A[1] = 4;A[2] = 5;
   B[0] = 2;B[1] = 4;B[2] = 4;
   Test(A, 3, B, 3, 4);
   
   return 0;
}

