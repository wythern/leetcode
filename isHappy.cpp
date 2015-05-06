#include "common.h"

class Solution {
public:
    bool isHappy(int n) {
        static set<int> visited;
        if (n == 1)
            return true;

        if(visited.find(n) != visited.end())
            return false;
        
        visited.insert(n);
        int l = nextN(n);
        return isHappy(l);
    }
    
    int nextN(int n){
        int l = 0;
        while(n > 0){
            l += (n%10)*(n%10);
            n /= 10;
        }
        return l;
    }
};

int main(int argc, char** argv){
    int n = 10;
    if(argc > 1)
        n = atoi(argv[1]);
    Solution s;
    cout << (s.isHappy(n) ? "True" : "false") << endl;
}
