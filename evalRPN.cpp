#include "common.h"

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		m_iTokenPos = 0;
		list<int> stackNumber;
		while (!endOfToken(tokens)){
			string token = nextToken(tokens);
			if (token.empty())
				continue;

			if (isNumber(token)){
				stackNumber.push_back(atoi(token.c_str()));
			} else if (isOperand(token)){
				int b = stackNumber.back();
				stackNumber.pop_back();
				int a = stackNumber.back();
				stackNumber.pop_back();
				int c = 0;
				switch (token[0])
				{
				case '+':
					c = a + b; break;
				case '-':
					c = a - b; break;
				case '*':
					c = a * b; break;
				case '/':
					c = a / b; break;
				default:
					break;
				}
				stackNumber.push_back(c);
			} else{
				cout << "ERROR, token " << token << " is neither digit nor operand." << endl;
				return INT_MIN;
			}
		}

		if (stackNumber.size() > 1){
			cout << "ERROR: stackNumber.size() > 1" << endl;
			return INT_MIN;
		}
		return stackNumber.back();
	}

	bool isNumber(string& token){
		int s = 0;
		int e = token.size();
		if (token[0] == '-'){
			s = 1;
			if (e == 1)
				return false;
		}

		for (int i = s; i < e; ++i){
			if ('0' <= token[i] && token[i] <= '9')
				continue;
			else
				return false;
		}
		return true;
	}

	bool isOperand(string& token){
		return token == "+" || token == "-" || token == "*" || token == "/";
	}

	string nextToken(vector<string>& tokens){
		if (m_iTokenPos < tokens.size())
			return tokens[m_iTokenPos++];
		else
			return string("");
	}

	bool endOfToken(vector<string>& tokens){
		return m_iTokenPos == tokens.size();
	}

private:
	int m_iTokenPos;
};


int main(int argc, char** argv){
	char *pTokens[] = { "4", "13", "-5", "/", "+" };
	vector<string> tokens;
	for (size_t i = 0; i < sizeof(pTokens)/sizeof(char*); i++)
	{
		tokens.push_back(pTokens[i]);
	}

	Solution s;
	int r = s.evalRPN(tokens);
	cout << "Result is " << r << endl;
	return 0;
}
