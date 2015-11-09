#include "common.h"

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (denominator == 0)
			return string("NAN");

		if (numerator == 0)
			return string("0");

		string strSign= (numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0) ? string("-") : string("");

		uint32_t absN = (numerator >= 0) ? numerator : -numerator;
		uint32_t absD = (denominator >= 0) ? denominator : -denominator;

		if (absN == absD){
			return strSign + string("1");
		} else if (absN > absD){
			ostringstream oss;
			oss << absN / absD << ((absN%absD) ? "." : "");
			return strSign + oss.str() + handleDecimal((absN%absD)*10, absD);
		} else {
			return strSign + string("0.") + handleDecimal(absN*10, absD);
		}
	}

	// calc decimal of a/b
	string handleDecimal(uint64_t  a, uint64_t b){
		map<pair<int, int>, int> calculated;
		string strDecimal;
		while (a){
			if (calculated.find(pair<int, int>(a, b)) != calculated.end()){
				// loop decimal;
				strDecimal.insert(calculated[pair<int, int>(a, b)], "(");
				strDecimal += ')';
				break;
			}else
				calculated[pair<int, int>(a, b)] = strDecimal.size();

			if (a < b){
				a *= 10;
				strDecimal += '0';
				continue;
			}

			strDecimal += '0' + a / b;
			a %= b;
			a *= 10;
		}

		return strDecimal;
	}
};

int main(int argc, char** argv){
	Solution s;
	cout << s.fractionToDecimal(-1, -2147483648) << endl;
	return 0;
}