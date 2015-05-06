class Solution {
public:
    int countPrimes(int n) {
        int c = 0;
        int* array = (int*)malloc(n*sizeof(int));
        memset(array, 0xFF, n*sizeof(int));
        array[0] = 0;
        array[1] = 0;
        for(int i = 0; i < n; ++i){
            if(array[i] != 0){
                ++c;
                int m = 2;
                while(m*i < n){
                    array[m*i] = 0;
                    ++m;
                }
            }
        }
        return c;
    }
};
