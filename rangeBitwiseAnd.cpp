#include "common.h"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        //common header method
        int p = 0;
        while(m != n){
            m >>= 1;
            n >>= 1;
            p += 1;
        }
        return m << p;
    }

    int rangeBitwiseAnd(int m, int n) {
        if(m == n)
            return m;

        int n_msb = get_msb(m);
        int m_msb = get_msb(n);
        
        if(m_msb != n_msb)
            return 0;
        
        int k = 0;
        int i = 1 << m_msb;
        while((m & i) == (n & i)){
            k |= (m & i);
            i >>= 1;
        }
        
        return k;
    }
    
    int get_msb(int n){
        if(n == 0)
            return -1;

        int m = 31;
        while(!(n & (1 << m)))
            m--; 
        return m;    
    }
};


int main(int argc, char** argv){
    int m = 0;
    int n = 0;
    if(argc > 2){
        m = atoi(argv[1]);
        n = atoi(argv[2]);
    }
    
    Solution s;
    cout << s.rangeBitwiseAnd(m, n) << endl;
    return 0;
}
