class Solution {
public:
    int titleToNumber(string s) {
        string::iterator it = s.begin();
        int n = 0;
        while(it != s.end()){
            n = n*26 + (*it - 'A' + 1);
            ++it;
        }
        return n;
    }
};
