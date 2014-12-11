#include "common.h"

class Solution {
public:
    bool isValid(string s) {
		if(s.empty())
			return true;

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
};


int main(int argv, char** argc)
{
	const char* pInput = "{}";
	if(argv > 1)
		pInput = argc[1];
	
	Solution s;
	std::cout << pInput;
	std::cout << (s.isValid(pInput) ? "is valid" : "is NOT valid") << std::endl;
	return 0;
}
