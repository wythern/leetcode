class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C - A)*(D - B) + (H - F)*(G - E) - intersect(A, C, E, G) * intersect(B, D, F, H);
    }

    int intersect(int x1, int x2, int x3, int x4){
        if(x1 <= x3 && x2 >= x3){
            if(x2 < x4)
                return x2 - x3;
            else
                return x4 - x3;
        }else if(x3 <= x1 && x4 >= x1){
            if(x4 < x2)
                return x4 - x1;
            else
                return x2 - x1;            
        }else
            return 0;
    }
};