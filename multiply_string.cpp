#include "common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        string r = multiplyImpl(num1, num2);
        int front = r.find_first_not_of('0');
        int end = r.size();
        if(r.find('.') != string::npos)
            end = std::max<int>(r.find_last_not_of('0'), r.find('.') - 1);
        return string(r.begin() + front, r.begin() + end);
    }

    string multiplyImpl(string num1, string num2) {
        if (num1.empty() || num2.empty()){
            return string();
        }

        if (num1.size() > num2.size())
            std::swap(num1, num2);

        //cout << "num1=" << num1 << "," << "num2=" << num2 << endl;
        string strResult(num1.size() + num2.size(), '0');
        int num2_dot = 0;
        if (num1.size() == 1){
            int number1 = num1[0] - '0';
            int carry = 0;
            string::reverse_iterator rItResultPos = strResult.rbegin();
            for(string::reverse_iterator rIt = num2.rbegin();
                rIt != num2.rend();
                ++rIt, ++rItResultPos){
                if(*rIt != '.'){
                    int interNum = (*rIt - '0') * number1 + carry;
                    int tail = interNum % 10;
                    *rItResultPos = tail + '0';
                    carry = interNum / 10;
                }else{
                    num2_dot = std::distance(rIt, num2.rbegin());
                }
            }
            if (carry != 0)
                *rItResultPos = carry + '0';

            if(num2_dot != 0)
                strResult.insert(std::distance(strResult.rbegin() + num2_dot, strResult.rend()), ".");

            return strResult;
        }

        int num1_dot = 0;
        int taillen = 0;
        for(string::reverse_iterator rIt = num1.rbegin();
            rIt != num1.rend();
            ++rIt, taillen++){
            if(*rIt != '.'){
                string intermedium = multiplyImpl(string(1, *rIt), num2);
                int carry = 0;
                string::reverse_iterator rItResultPos = strResult.rbegin() + taillen;
                for(string::reverse_iterator rItInter = intermedium.rbegin();
                    rItInter != intermedium.rend() && rItResultPos != strResult.rend();
                    ++rItInter, ++rItResultPos){
                    if(*rItInter != '.'){
                        int interNum = ((*rItInter - '0') + (*rItResultPos - '0') + carry);
                        *rItResultPos = interNum % 10 + '0';
                        carry = interNum / 10;
                    }else{
                        num2_dot = std::distance(rItInter, intermedium.rbegin()) + taillen;
                    }
                }
                if (carry != 0)
                    *rItResultPos = carry + '0';
            }else{
                num1_dot = std::distance(rIt, num1.rbegin());
            }
        }

        if(num1_dot || num2_dot)
            strResult.insert(std::distance(strResult.rbegin() + num1_dot + num2_dot, strResult.rend()), ".");

        return strResult;
    }
};	


int main(int argc, char** argv){
    Solution s;
    if (argc < 3)
        exit(1);

    cout << s.multiply(argv[1], argv[2]) << endl;
	return 0;
}
