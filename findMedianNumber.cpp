#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            std::cout << __FUNCTION__ << std::endl;
            for(int i = 0; i < m; ++i)
                cout << A[i] << ",";
            cout << endl;
            for(int i = 0; i < n; ++i)
                cout << B[i] << ",";
            cout << endl;

			std::vector<int> vA(A, A+m);
			std::vector<int> vB(B, B+n);
			return findMedianInVector(vA, vA.begin(), vA.end(),
									  vB, vB.begin(), vB.end());
        }

private:
    double resolveMedianNumber(std::vector<int>& vA, int nA,
                               std::vector<int>& vB, int nB){
        //assert(vA[nA] < vB[nB]);
        int sA = vA.size();
        int sB = vB.size();

		if((sA + sB)%2){
			return (nA == (sA+sB)/2 - 1) ? vA[nA] : vB[nB];
		}else{
			return (nA == (sA+sB)/2) ? vA[nA] : vB[nB];
		}
    }
    
    double findMedianInVector(std::vector<int>& vA,
							  std::vector<int>::iterator iterABegin,
							  std::vector<int>::iterator iterAEnd,
							  std::vector<int>& vB,
							  std::vector<int>::iterator iterBBegin,
							  std::vector<int>::iterator iterBEnd){

		std::cout << __FUNCTION__ << std::endl;
		for(std::vector<int>::iterator iter = iterABegin; iter < iterAEnd; ++iter){
			std::cout << *iter << ",";
		}
		std::cout << std::endl;
		for(std::vector<int>::iterator iter = iterBBegin; iter < iterBEnd; ++iter){
			std::cout << *iter << ",";
		}
		std::cout << std::endl;
		
        if (std::distance(iterABegin, iterAEnd) == 1 &&
            std::distance(iterBBegin, iterBEnd) == 1){
            return resolveMedianNumber(vA, std::distance(vA.begin(), iterABegin),
                                       vB, std::distance(vB.begin(), iterBBegin));
		}

        std::vector<int>::iterator iterMidA = iterABegin + std::distance(iterABegin, iterAEnd)/2;
        std::vector<int>::iterator iterMidB = iterBBegin + std::distance(iterBBegin, iterBEnd)/2;

        if (*iterMidA == *iterMidB)
            return *iterMidA;
        if (*iterMidA > *iterMidB){
            //std::swap(vA, vB);
            //std::swap(iterMidA, iterMidB);
			return findMedianInVector(vB, iterMidB, iterBEnd,
									  vA, iterABegin, iterMidA);
        }
        // A[m/2, findinA(MidB)] and B[findinB(MidA), n/2]
		/*
        return findMedianInVector(vA, iterMidA, std::lower_bound(iterMidA, iterAEnd, *iterMidB),
                                  vB, std::lower_bound(iterBBegin, iterMidB, *iterMidA), iterMidB);
		*/
		return findMedianInVector(vA, iterMidA, iterAEnd,
                                  vB, iterBBegin, iterMidB);

    }
};

int main()
{
   cout << "Hello World" << endl; 
   Solution s;
   int A[] = {1, 3, 5, 7, 9};
   int B[] = {2, 4, 6, 8, 10, 11};
   int m = sizeof(A)/sizeof(int);
   int n = sizeof(B)/sizeof(int);
   
   std::cout << s.findMedianSortedArrays(A, m, B, n) << std::endl;
   
   return 0;
}

