/*
 *For example, given array S = {-1 0 1 2 -1 -4},
 *  A solution set is:
 *  (-1,  0, 1)
 *  (-1, -1, 2)
*/

#include "common.h"

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if (num.empty())
            return vector<vector<int> >();

        int n = num.size();
        //vector<vector<vector<int> > > vMap(3*n);
        int sizes[] = {n, n, n};
        int*** vMap = (int***)mallocNdIntArray(3, sizes);
        vector<vector<int> > vResult;

        for(int i = 0; i < n; ++i)
            vMap[i][i][i] = num[i]*3;

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < k; ++i)
                for(int j = 0; j < i; ++j){
                    vMap[i][j][k] = (vMap[i][i][i] + vMap[j][j][j] + vMap[k][k][k])/3;
                    if(vMap[i][j][k] == 0){
//                        std::cout << i << "," << j  << "," << k << std::endl;
//                        std::cout << num[i] << "," << num[j]  << "," << num[k] << std::endl;
//                        std::cout << vMap[i][i][i] << "," << vMap[j][j][j] << "," << vMap[k][k][k] << std::endl;
                        vector<int> vSolution;
                        vSolution.push_back(num[i]);
                        vSolution.push_back(num[j]);
                        vSolution.push_back(num[k]);
                        std::sort(vSolution.begin(), vSolution.end());
                        vResult.push_back(vSolution);
                        getchar();
                    }
                }

        //std::unique(vResult.begin(), vResult.end());
        return vResult;
    }
};


int main(int argc, char** argv)
{
    Solution s;
    int A[] = {-1, 0, 1, 2, -1, -4};
    vector<int> vInput(A, A + sizeof(A)/sizeof(int));
    vector<vector<int> > v = s.threeSum(vInput);

    for(int i = 0; i < v.size(); ++i){
        vector<int>::iterator it = v[i].begin();
        while(it != v[i].end()){
            std::cout << *it++ << ",";
        }
        std::cout << std::endl;
    }

    return 0;
}

