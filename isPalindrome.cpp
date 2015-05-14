class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            if(!isAlphanumeric(s[i])){
                ++i;
                continue;
            }
            if(!isAlphanumeric(s[j])){
                --j;
                continue;
            }
            if(toLower(s[i]) != toLower(s[j]))
                return false;

            ++i;
            --j;
        }
        return true;
    }
    
    bool isAlphanumeric(char ch){
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
    
    char toLower(char ch){
        if(ch >= 'A' && ch <= 'Z')
            return ch - ('A' - 'a');

        return ch;
    }
};
