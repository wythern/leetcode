class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        vector<int> d(m, 0);
        d[0] = triangle[0][0];
        for(int i = 1; i < m; ++i){
            int n = triangle[i].size();
            int t = d[0];
            for(int j = 0; j < n; ++j){
                if(j == 0)
                    d[j] = triangle[i][0] + t;
                else if(j == n - 1)
                    d[j] = triangle[i][j] + t;
                else{
                    int d_new = triangle[i][j] + min(t, d[j]);
                    t = d[j];
                    d[j] = d_new;
                }
            }
        }
        
        return *min_element(d.begin(), d.end());
    }
};
