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

    vector<int> getRow(int rowIndex) {
        vector<int> row;
        if(rowIndex < 0)
            return row;

        int c = rowIndex + 1;
        row.insert(row.end(), c, 1);
        for(int i = 2; i <= c; ++i){
            row[0] = 1;
            int t = row[0];
            for(int j = 1; j < i - 1; ++j){
                int newNum = t + row[j];
                t = row[j];
                row[j] = newNum;
            }
        }
        return row;
    }
};
