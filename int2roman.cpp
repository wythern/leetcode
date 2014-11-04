/*
 *
 */

#include "common.h"

class Solution {
public:
    string intToRoman(int num) {
        if (num <= 0)
            return "";

        const char* basedigits[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        const char* highdigits[] = {"X", "L", "C", "D", "M"};
        int highdigitsNumber[] = {10, 50, 100, 500, 1000};
        string strRoman;
        
        int i = sizeof(highdigitsNumber)/sizeof(int) - 1;
        while(i >= 0){
            int digitCnt = num/highdigitsNumber[i];
            num -= digitCnt*highdigitsNumber[i];

            if(digitCnt < 4){
                while(digitCnt) {
                    strRoman.append(highdigits[i]);
                    digitCnt--;
                }
            }else{
                strRoman.append(highdigits[i]);
                strRoman.append(highdigits[i+1]);
            }
            --i;
        }

        int digit = num%10;
        if(digit > 0)
            strRoman.append(basedigits[digit]);

        return strRoman;
    }
};


int main(int argc, char** argv)
{
    Solution s;
    std::cout << s.intToRoman(89) << std::endl;
    std::cout << s.intToRoman(97) << std::endl;
    std::cout << s.intToRoman(101) << std::endl;
    std::cout << s.intToRoman(1513) << std::endl;
    return 0;
}

