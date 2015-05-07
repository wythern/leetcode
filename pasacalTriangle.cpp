class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > pascalTriangle;
        if(numRows == 0)
            return pascalTriangle;

        vector<int> upLv(1, 1);
        pascalTriangle.push_back(upLv);
        for(int i = 2; i <= numRows; ++i){
            vector<int> downLv;
            downLv.push_back(upLv[0]);
            for(int j = 1; j < i - 1; ++j){
                downLv.push_back(upLv[j - 1] + upLv[j]);
            }
            downLv.push_back(upLv[i - 2]);
            pascalTriangle.push_back(downLv);
            swap(upLv, downLv);
        }
        return pascalTriangle;
    }
};
