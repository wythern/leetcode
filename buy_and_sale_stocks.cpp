#include "common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
            return 0;

        vector<int> f(n, INT_MIN);
        vector<int>& p = prices;

        f[n - 1] = 0;
        f[n - 2] = p[n - 1] - p[n - 2];
        int m = p[n - 1];
        for(int i = n - 3; i >= 0; --i){
            if(p[i + 1] > m){
                m = p[i + 1];
                f[i] = p[i + 1] - p[i];
            }else
                f[i] = f[i + 1] + p[i + 1] - p[i];
        }
        
        vector<int>::iterator it = max_element(f.begin(), f.end());
        cout << "start buy at " << distance(f.begin(), it) << endl;
        int maxProfit = *it;
        
        if(maxProfit < 0)
            return 0;
        
        return maxProfit;
    }

    int maxProfitII(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        
        int d = 0;
        for(int i = 0; i < prices.size() - 1; ++i){
            if(prices[i + 1] > prices[i]){
                d += prices[i + 1] - prices[i];
            }
        }

        return d;
    }

};

int main(int argc, char** argv){
	int array[] = {3, 2, 6, 5, 0, 3};

    vector<int> vA(array, array + sizeof(array)/sizeof(int));
	Solution s;
	int n = s.maxProfit(vA);
	cout << "Max profilt = " << n << endl;
	return 0;
}
