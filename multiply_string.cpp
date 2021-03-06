#include "common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        int num1dot_tail = 0;
        int num2dot_tail = 0;
        string pureNum1 = preProcessString(num1, &num1dot_tail);
        string pureNum2 = preProcessString(num2, &num2dot_tail);

        string r = multiplyImpl(pureNum1, pureNum2);
        int dotPos = std::distance(r.rbegin() + num1dot_tail + num2dot_tail, r.rend());
        r.insert(dotPos, 1, '.'); // add decimal dot back.
        cout << r << endl;

        int front = std::min<int>(r.find_first_not_of('0'), dotPos);
        int end = std::max<int>(r.find_last_not_of('0'), dotPos);
        if (front == dotPos)
            front = dotPos - 1;
        if (end != dotPos)
            end++; 

        return string(r.begin() + front, r.begin() + end);
    }

    string preProcessString(string& strNum, int* dotTail){
        int pos = strNum.find('.');
        *dotTail = 0;
        if(pos != string::npos){
            *dotTail = strNum.size() - pos - 1;
            strNum.erase(pos, 1);
        }
        return strNum;
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
                int interNum = (*rIt - '0') * number1 + carry;
                int tail = interNum % 10;
                *rItResultPos = tail + '0';
                carry = interNum / 10;
            }
            if (carry != 0)
                *rItResultPos = carry + '0';

            return strResult;
        }

        int num1_dot = 0;
        int taillen = 0;
        for(string::reverse_iterator rIt = num1.rbegin();
            rIt != num1.rend();
            ++rIt, taillen++){
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
        }

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
