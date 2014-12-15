#include "common.h"

class Solution {
public:
	vector<string> generateParenthesis(int n) {

        return generateParenthesisImpl(n);
    }

	vector<string> generateParenthesisImpl_wrong(int n) {
        if(0 >= n)
            return vector<string>();
		if(1 == n){
			return vector<string>(1, string("()"));
		}

		// f1(n) == "()" + f(n-1);
		// f2(n) == "(" + f(n-1) + ")";
		// f3(n) == f(n-1) + "()";
		vector<string> vStr(generateParenthesisImpl(n-1));
		vector<string> vStrN_1(vStr.size(), string("()"));
		int i = 0;
		for(vector<string>::iterator it = vStrN_1.begin();
			it != vStrN_1.end();
			++it, ++i){
			*it += vStr[i];
		}

		i = 0;
		vector<string> vStrN_2(vStr.size(), string("("));
		for(vector<string>::iterator it = vStrN_2.begin();
			it != vStrN_2.end();
			++it, ++i){
			*it += vStr[i];
			*it += string(")");
		}

		i = 0;
		vector<string> vStrN_3(vStr.size(), string("()"));
		for(vector<string>::iterator it = vStrN_3.begin();
			it != vStrN_3.end();
			++it, ++i){
			vStr[i] += *it;
		}

		set<string> setStr;
		setStr.insert(vStr.begin(), vStr.end());
		setStr.insert(vStrN_1.begin(), vStrN_1.end());
		setStr.insert(vStrN_2.begin(), vStrN_2.end());
		return vector<string>(setStr.begin(), setStr.end());
	}

	vector<string> generateParenthesisImpl(int n) {
		int stack = 0;
		string strBase = string(n, '(') + string(n, ')');
		vector<string> vStrParenthesis;
		allRange(strBase, 0, strBase.size(), vStrParenthesis);
		return vStrParenthesis;
	}

	void allRange(string& strBase, int s, int e, vector<string>& vStrParenthesis){
		if(s >= e){
			if(isValid(strBase))
				vStrParenthesis.push_back(strBase);
			return;
		}

		set<int> numDict;
		numDict.insert(strBase[s]);
		allRange(strBase, s+1, e, vStrParenthesis);
		for(int i = s + 1; i < e; ++i){
			if(strBase[s] != strBase[i] &&
			   numDict.find(strBase[i]) == numDict.end()){
				numDict.insert(strBase[i]);
				std::swap(strBase[s], strBase[i]);
				allRange(strBase, s+1, e, vStrParenthesis);
				std::swap(strBase[s], strBase[i]);
			}
		}
	}

	bool isValid(string s) {
		if(s.empty())
			return false;

		const char* parentheses = "()[]{}";
		std::stack<char> symbolStack;
		for(string::iterator it = s.begin();
			it != s.end();
			++it){
			int pos = 0;
			switch (*it){
			case '(':
			case '[':
			case '{':
				symbolStack.push(*it);
				continue;
			case ')':
				pos = 0;
				break;
			case ']':
				pos = 2;
				break;
			case '}':
				pos = 4;
				break;
			default:
				return false;
			}

			if(symbolStack.empty())
				return false;
			char ch = symbolStack.top();
			symbolStack.pop();
			if(ch != parentheses[pos])
				return false;
		}

		return symbolStack.empty();
    }

    vector<string> generateParenthesis_from_other(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
    }

};

int main(int argv, char** argc)
{
	Solution s;
	for(int i = 0; i < 6; ++i){
		std::cout << "--------------------" << i << "--------------------" << std::endl;
		vector<string> vStr(s.generateParenthesis_from_other(i));
		printArray(vStr);
		std::cout << "--------------------=--------------------" << std::endl;
	}
	return 0;
}
