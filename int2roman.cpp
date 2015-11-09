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
        const char* highdigits[] = {"X", "L", "C", "D",  "M"};
        int highdigitsNumber[] =   { 10,  50, 100, 500, 1000};
        string strRoman;
        
        int i = sizeof(highdigitsNumber)/sizeof(int) - 1;
        while(i >= 0 && num != 0){
            int digitCnt = num/highdigitsNumber[i];
            num -= digitCnt*highdigitsNumber[i];

            if(digitCnt == 4){
                strRoman.append(highdigits[i]);
                strRoman.append(highdigits[i + 1]);
            }else if (digitCnt == 9){
                strRoman.append(highdigits[i]);
                strRoman.append(highdigits[i + 2]);
            }else if(digitCnt < 4){
                while(digitCnt) {
                    strRoman.append(highdigits[i]);
                    digitCnt--;
                }
            }else if(digitCnt < 9){
                strRoman.append(highdigits[i + 1]);
                while(digitCnt != 5) {
                    strRoman.append(highdigits[i]);
                    digitCnt--;
                }
            }
            i -= 2;
        }

        int digit = num%10;
        if(digit > 0)
            strRoman.append(basedigits[digit]);

        return strRoman;
    }

    int findIndex(const char array[], const char ch) const {
        int i = 0;
        for(; i < 7; ++i)
            if(ch == array[i])
                return i;
    }

    int romanToInt(string s){
        if(s.empty())
            return 0;

        const char  pszbasedigit[] = {'I', 'V', 'X', 'L', 'C', 'D',  'M'};
        const int   intbasedigit[] = {  1,   5,  10,  50, 100, 500, 1000};
        int pos = 0;
        int base = 0;
        int st = 0; // 0 for keep forward, 1 for change digit, -1 for change base.
        int i = 0;
        int j = 0;
        while(pos < s.length() - 1){
            int i = findIndex(pszbasedigit, s[pos]);
            int j = findIndex(pszbasedigit, s[pos + 1]);

            if(i < j)
                st = 1; // IV case;
            else if (i > j)
                st = -1; // VI case;
            else
                st = 0; // III case;

            if (1== st){
                base += intbasedigit[j] - intbasedigit[i];
                pos +=2;
                st = 0;
            }else if (-1 == st){
                base += intbasedigit[i]; // why not [i] + [j] is because we have cases like CXL (140);
                pos ++;
            }else {
                base += intbasedigit[i];
                pos ++;
            }
        }

        // tail
        if(pos == s.length() - 1){
            int i = findIndex(pszbasedigit, s[pos]);
            if (1 == st){
                ;//assert(0);
            }else if (-1 == st){
                base += intbasedigit[i];
            }else {
                base += intbasedigit[i];
            }
        }

        return base;
    }
};


int main(int argc, char** argv)
{
    Solution s;

    for(int i = 0; i < 4000; ++i){
        if (i != s.romanToInt(s.intToRoman(i))){
            std::cout << "ERROR in " << i << std::endl;
            std::cout << i << " " << s.intToRoman(i) << " " << s.romanToInt(s.intToRoman(i)) << std::endl;
        }
    }

    return 0;
}

