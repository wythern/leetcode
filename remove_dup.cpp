#include "common.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(NULL == A || 0 == n)
            return 0;

        int iLeft = -1;
        int nCnt = 0;
        int i = 0;
        int pos = 0;
        while(i < n){
            if(iLeft == -1 || A[iLeft] != A[pos]){
				if(iLeft + 1 != pos)
					memmove(A + iLeft + 1, A + pos, (n - i)*sizeof(int));

                iLeft++;
				pos = iLeft;
                nCnt++;
            }
			pos++;                
            i++;
        }

        return nCnt;
    }

	int removeDuplicates1(int A[], int n) {
		if (NULL == A || 0 == n)
			return 0;

		int i = 0;
		int curr = 0;
		int prev = -1;
		int c = 0;
		while(i < n){
			//A switch method??
			//what's the std::unique src code?
		}
	}
};


int main(int argc, char** argv)
{
    Solution s;
	int n = 2;
	if(argc > 1){
		n = atoi(argv[1]);
	}

	vector<int> vInts(generateRandomIntVector(n, 1, 10));
	std::sort(vInts.begin(), vInts.end());
	int* pA = (int*)malloc(vInts.size() * sizeof(int));
	for(int i = 0; i < vInts.size(); ++i)
		pA[i] = vInts[i];

	vector<int> vRef(pA, pA+vInts.size());
	int kRef = std::distance(vRef.begin(), std::unique(vRef.begin(), vRef.end()));
	vRef.erase(vRef.begin() + kRef, vRef.end());

	printArray(pA, vInts.size(), "A");	
	int k = s.removeDuplicates(pA, vInts.size());
	printArray(pA, k, "UniqueA");

	printArray(&vRef[0], vRef.size(), "Ref Unique A");

	vector<int> v1(pA, pA + k);
	if(vRef != v1)
		std::cout << "NOT OK" << std::endl;
	else
		std::cout << "OK" << std::endl;

	return 0;
}
