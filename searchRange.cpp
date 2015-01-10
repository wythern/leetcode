#include "common.h"

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        return searchRange(A, 0, n, target);
    }

    vector<int> searchRange(int A[], int s, int e, int target) {
        if (NULL == A || s >= e)
            return vector<int>(2, 0);

        int m = s + (e-s)/2;
        if(A[m] < target){
            return searchRange(A,  m + 1, e, target);
        }else if(A[m] > target){
            return searchRange(A, s, m, target);
        }else{ // A[m] == target
            // left
            int *B = A + s;
            int c = m - s + 1;
            int l = 0;
            int i = 0;
            while(c > 0){
                i = l;
                int step = c/2;
                i += step;
                if( B[i] < target){
                    l = i+1;
                    c -= step + 1;
                }else
                    c = step;
            }
            l += s;

            // right
            B = A + m + 1;
            c = e - m;
            i = 0;
            int r = 0;
            while(c > 0){
                i = r;
                int step = c/2;
                if(B[i] <= target){
                    r = i + 1;
                    c -= step + 1;
                }else{
                    c = step;
                }
            }
            r += m;
            vector<int> vRange;
            vRange.push_back(l);
            vRange.push_back(r);
            return vRange;
        }
    }
};

int main(int argc, char** argv){

    if(argc < 3){
        printf("%s input target.\n", argv[0]);
		return 0;
	}

    Solution s;
	string strPattern(argv[1]);
	vector<int> num;
	for(int i = 0; i < strPattern.size(); ++i){
		char ch = strPattern[i];
		num.push_back(ch - '0');
	}
	printContainer<vector<int> >(num, num.size(), "Input");

    vector<int> vRange = s.searchRange((int*)&num[0], num.size(), atoi(argv[2]));
    printContainer<vector<int> >(vRange, vRange.size(), "Result");
	return 0;
}
