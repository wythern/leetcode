#include "common.h"


//DP with memorized search, actually we can have a O(1) space method.
class Solution {
public:
    int rob(vector<int> &num) {
        if(num.empty())
            return 0;

        vector<int> map(num.size(), -1);
        return robImpl(num, 0, map);
    }
    
    int robImpl(vector<int>& num, int i, vector<int>& map){
        if(i >= num.size())
            return 0;
        
        if(i == num.size() - 1)
            return num[i];

        if(map[i] != -1)
            return map[i];

        map[i] = std::max((num[i] + robImpl(num, i + 2, map)), (num[i+1] + robImpl(num, i + 3, map)));
        return map[i];
    }
};
