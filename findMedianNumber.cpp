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
        
        int MidA = A[m/2];
        int MidB = B[n/2];
        if (!m && !n)
            return (MidA + MidB)/2;
        if (MidA == MidB)
            return MidA;
        if (MidA > MidB)
            return findMedianSortedArrays(A, m/2, B + n/2, n - n/2);
        if (MidA < MidB)
            return findMedianSortedArrays(A + m/2, m - m/2, B, n/2);
    }

#include <iostream>

    using namespace std;

    class Solution {
    public:
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            std::cout << __FUNCTION__ << std::endl;
            for(int i = 0; i < m; ++i)
                cout << A[i];
            cout << endl;
            for(i = 0; i < n; ++i)
                cout << B[i];
            cout << endl;

        }
    };

private:
    double resolveMedianNumber(std::vector<int>& vA, int nA,
                               std::vector<int>& vB, int nB){
        //assert(vA[nA] < vB[nB]);

        int sA = vA.size();
        int sB = vB.size();

        
    }
    
    double findMedianInVector(std::vector<int>& vA,
                       std::vector<int>::iterator& iterABegin,
                       std::vector<int>::iterator& iterAEnd,
                       std::vector<int>& vB,
                       std::vector<int>::iterator& iterBBegin,
                       std::vector<int>::iterator& iterBEnd){
        if (std::distance(iterABegin, iterAEnd) == 0 &&
            std::distance(iterBBegin, iterBEnd) == 0)
            return resolveMedianNumber(vA, std::distance(vA.begin(), iterABegin),
                                       vB, std::distance(vB.begin(), iterBBegin));

        std::vector<int>::iterator iterBeginA = vA.begin() + rA.first;
        std::vector<int>::iterator iterBeginB = vB.begin() + rB.first;
        std::vector<int>::iterator iterEndA = vA.begin() + rA.second;
        std::vector<int>::iterator iterEndB = vB.begin() + rB.second;
        std::vector<int>::iterator iterMidA = vA.begin() + ((rA.first + rA.second)/2);
        std::vector<int>::iterator iterMidB = vB.begin() + ((rB.first + rB.second)/2);

        if (*iterMidA == *iterMidB)
            return *iterMidA;
        if (*iterMidA > *iterMidB){
            std::swap(vA, vB);
            std::swap(*iterMidA, *iterMidB);
        }
        // A[m/2, findinA(MidB)] and B[findinB(MidA), n/2]
        return findMedianInVector(vA, iterMidA,
                                  std::lower_bound(iterMidA. iterEndA, *iterMidB),
                                  vB, std::lower_bound(iterBeginB. iterMidB, *iterMidA),
                                  iterMidB);
    }
};

int main()
{
   cout << "Hello World" << endl; 
   Solution s;
   int A[] = {1, 3, 5, 7, 9};
   int B[] = {2, 4, 6, 8, 10};
   int m = sizeof(A)/sizeof(int);
   int n = sizeof(B)/sizeof(int);
   
   std::cout << s.findMedianSortedArrays(A, m, B, n) << std::endl;
   
   return 0;
}

