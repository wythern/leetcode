/*
 *
 *
 */
#include "common.h"

class Solution {
public:
    string longestCommonPrefix2(vector<string> &strs) {
        if(strs.empty())
            return "";
        
        //std::string strPrefix;
        bool bStop = false;
        int pos = 0;
        while(!bStop){
            char ch = strs[0][pos];
            if('\0' == ch)
                break;

            for(int i = 1; i < strs.size(); ++i){
                if(pos >= strs[i].length() || strs[i][pos] != ch){
                    bStop = true;
                    break;
                }
            }

            if(!bStop){
                ++pos;
            }
        }

        return string(strs[0].begin(), strs[0].begin() + pos);
    }
};

int main(int argc, char** argv)
{
    Solution s;
    std::string A("");
    std::string B("");
    std::vector<std::string> strs;
    strs.push_back(A);
    //strs.push_back(B);
    std::cout << s.longestCommonPrefix2(strs) << std::endl;
    return 0;
}

