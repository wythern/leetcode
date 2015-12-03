#include "common.h"

class Solution {
public:
	vector<string> addOperators(string num, int target) {
		vector<string> expressions;
		string strCandidate;
		int64_t curRslt = 0;
		for (size_t i = 0; i < num.size(); i++)
		{
			curRslt = curRslt * 10 + num[i] - '0';
			strCandidate += num[i];
			addOperatorsImpl_reference(num.c_str(), i + 1, num.size(), curRslt, strCandidate, curRslt, target, strCandidate, expressions);
		}
		return expressions;
	}

	void addOperatorsImpl_reference(const char* pszNum, int start, int end, int64_t lastOperand, string& strLastOperand,
									int64_t result, int target, string& candidate, vector<string>& vExpressions){
		if (start >= end){
			if (result == target){
				vExpressions.push_back(candidate);
			}
			return;
		}

		int64_t nextOperand = 0;
		string strNextOperand;
		for (size_t i = start; i < end; i++)
		{
			nextOperand = nextOperand * 10 + pszNum[i] - '0';
			strNextOperand += pszNum[i];
			for (size_t j = 0; j < 3; j++)
			{
				string newStr = candidate;
				switch (j)
				{
				case 0: // +
					newStr += '+';
					newStr += strNextOperand;
					addOperatorsImpl_reference(pszNum, i + 1, end, nextOperand, strNextOperand, result + nextOperand, target, newStr, vExpressions);
					break;
				case 1: // -
					newStr += '-';
					newStr += strNextOperand;
					addOperatorsImpl_reference(pszNum, i + 1, end, -nextOperand, strNextOperand, result - nextOperand, target, newStr, vExpressions);
					break;
				case 2: // *
				default:
					newStr += '*';
					newStr += strNextOperand;
					addOperatorsImpl_reference(pszNum, i + 1, end, lastOperand*nextOperand, strNextOperand, result - lastOperand + lastOperand*nextOperand, target, newStr, vExpressions);
					break;
				}
			}

			if (pszNum[i] == '0')
				break;
		}
	}

	vector<string> addOperators_BF(string num, int target) {
		vector<string> expressions;
		string strCandidate;
		addOperatorsImpl(num.c_str(), 0, num.size(), target, strCandidate, expressions);
		return expressions;
	}

	void addOperatorsImpl(const char* pszNum, int start, int end, int target, string& candidate, vector<string>& vExpressions){
		if (start >= end){
			if (target == evalString(candidate))
				vExpressions.push_back(candidate);
			return;
		}

		if ((pszNum[start] != '0') || (start + 1 == end)){
			string subCandidate = candidate + pszNum[start];
			addOperatorsImpl(pszNum, start + 1, end, target, subCandidate, vExpressions);
		}

		int i = start;		
		if(i + 1 < end){
			candidate += pszNum[i];
			for (size_t j = 0; j < 3; j++)
			{
				string subCandidate = candidate;
				switch (j)
				{
				case 0: // +
					subCandidate.push_back('+');
					addOperatorsImpl(pszNum, i + 1, end, target, subCandidate, vExpressions);
					break;
				case 1: // -
					subCandidate.push_back('-');
					addOperatorsImpl(pszNum, i + 1, end, target, subCandidate, vExpressions);
					break;
				case 2: // * 
					subCandidate.push_back('*');
					addOperatorsImpl(pszNum, i + 1, end, target, subCandidate, vExpressions);
					break;
				default:
					break;
				}
			}
		}
	}

	struct ExpressionElem{
		int       type; // 0: operand, 1: operator
		union{
			int    num; // operand;
			char op[2]; // operator & its priority;
		};

		bool operator < (const ExpressionElem& rhs) const{
			if (type == 0)
				return num < rhs.num;
			else
				return op[1] < rhs.op[1];
		}
	};

	int evalString(string& strExp){
		int pos = 0;
		//std::priority_queue<ExpressionElem, std::vector<ExpressionElem>>  operatorQueue;
		stack<ExpressionElem>  operatorQueue;
		queue<ExpressionElem> elemQueue;
		while (pos < strExp.size())
		{
			int operand = 0;
			if (strExp[pos] >= '0' && strExp[pos] <= '9'){
				while (strExp[pos] >= '0' && strExp[pos] <= '9'){
					operand = operand * 10 + strExp[pos] - '0';
					++pos;
				}
				ExpressionElem elem;
				elem.type = 0;
				elem.num = operand;
				elemQueue.push(elem);
			} else{
				ExpressionElem elem;
				elem.type = 1;
				elem.op[0] = strExp[pos];
				elem.op[1] = (strExp[pos] == '*') ? 1 : 0;

				if (!operatorQueue.empty() && operatorQueue.top().op[1] >= elem.op[1]){
					elemQueue.push(operatorQueue.top());
					operatorQueue.pop();
				}
				operatorQueue.push(elem);
				++pos;
			}
		}

		while (!operatorQueue.empty()){
			elemQueue.push(operatorQueue.top());
			operatorQueue.pop();
		}

		stack<int> operandStack;
		while (!elemQueue.empty())
		{
			ExpressionElem elem = elemQueue.front();
			elemQueue.pop();

			if (elem.type == 0){
				operandStack.push(elem.num);
			} else{
				int a = operandStack.top();
				operandStack.pop();
				int b = operandStack.top();
				operandStack.pop();

				switch (elem.op[0])
				{
				case '+':
					a = a + b;
					break;
				case '-':
					a = b - a;
					break;
				case '*':
					a = a * b;
					break;
				default:
					break;
				}

				operandStack.push(a);
			}
		}

		//assert operandStack.size() == 1;
		return operandStack.top();
	}
};

int main(int argc, char** argv){
	Solution s;
	vector<string> exps = s.addOperators("2147483648", - 2147483648);

	printContainer<vector<string>>(exps, exps.size());
	return 0;
}
