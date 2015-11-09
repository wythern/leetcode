#include "common.h"

class Solution {
public:
	enum NODE_STATUS{
		MATCH_PARENTHESE = 0,
		LEFT_PARENTHESE  = 1,
		RIGHT_PARENTHESE = 2
	};
	
	struct Node{
		char        ch;
		NODE_STATUS st;
	};

	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;

		int l = 0;
		vector<Node> vNode;
        for(string::iterator it = s.begin();
			it != s.end();
			++it){
			if(*it == '('){
				// push
				Node node;
				node.ch = *it;
				node.st = LEFT_PARENTHESE;
				vNode.push_back(node);
			}else if(*it == ')'){
				// pop
				if(!vNode.empty()){
					vector<Node>::reverse_iterator rIt = vNode.rbegin();
					while(rIt != vNode.rend() && rIt->st == MATCH_PARENTHESE){
						++rIt;
					}

					if(rIt != vNode.rend() && rIt->st == LEFT_PARENTHESE){
						rIt->st = MATCH_PARENTHESE;
						continue;
					}
				}

				Node node;
				node.ch = *it;
				node.st = RIGHT_PARENTHESE;
				vNode.push_back(node);
			}
		}

		//dumpNodeVector(vNode);

		int maxL = 0;
		for(int i = 0; i < vNode.size(); ++i){
			if(vNode[i].st != MATCH_PARENTHESE){
				if(l > maxL)
					maxL = l;
				l = 0;
			}else{
				l += 2;
			}
		}

		if(l > maxL)
			maxL = l;

		return maxL;
    }

	void dumpNodeVector(vector<Node>& vNode){
		const char* NodeStatus[] = {"MATCH_PARENTHESE", "LEFT_PARENTHESE", "RIGHT_PARENTHESE"};
		cout << "[";
		for(int i = 0; i < vNode.size(); ++i){
			cout << NodeStatus[vNode[i].st] << ",";
		}
		cout << "]";
		cout << endl;
	}
};

int main(int argc, char** argv){
	if(argc < 2){
		cout << argv[0] << " inputString" << endl;
		return 0;
	}

	Solution s;
	cout << "Longest () size == " << s.longestValidParentheses(string(argv[1])) << endl;
	return 0;
}
