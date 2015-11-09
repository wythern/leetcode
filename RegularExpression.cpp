#include "common.h"

class Node{
public:
	Node() : strPattern("")
		   , bSelfLoop(false)
	{}

	~Node()
	{
		strPattern.clear();
#if 0
		for(std::set<Node*>::iterator it = vConnectNodes.begin();
			it != vConnectNodes.end();
			++it)
			delete *it;

		vConnectNodes.clear();
#endif
	}

public:
	std::string strPattern;
	bool bSelfLoop;
	std::set<Node*> vConnectNodes;
};

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		Node* pNode = &nodeGraph;
		compilePattern(p);
        return isMatchPattern(s, pNode);
    }

private:
	bool isMatchPattern(const char *s, Node* pNode){
		bool ret = false;
		for(std::set<Node*>::iterator it = pNode->vConnectNodes.begin();
			!ret && it != pNode->vConnectNodes.end();
			++it){
			if(*s == '\0'){
				ret |= (std::string("END") == (*it)->strPattern);
			}else if(std::string(s, 0, 1) == (*it)->strPattern){
				ret |= isMatchPattern(s+1, *it);
			}else if(std::string(".") == (*it)->strPattern){
				ret |= isMatchPattern(s+1, *it);
			}else if(std::string("START") == (*it)->strPattern){
				ret |= isMatchPattern(s, *it);
			}
		}

		return ret;
	}

	bool compilePattern(const char *p){
		int i = 0;
		Node* pCurrNode = &nodeGraph;
		//Node* pPrevNode = &nodeGraph;
		std::set<Node*> vPrevNode;
		nodeGraph.strPattern.assign("START");
		while(p[i] != '\0'){
			if(p[i] != '*'){
				if(pCurrNode->strPattern.compare(std::string(p, i, 1)) || (p[i+1] != '*') || !pCurrNode->bSelfLoop){
					Node* pNode = new Node;
					pNode->strPattern.assign(p, i, 1);
					pCurrNode->vConnectNodes.insert(pNode);
					for(std::set<Node*>::iterator it = vPrevNode.begin();
						it != vPrevNode.end();
						++it){
						(*it)->vConnectNodes.insert(pNode);
					}

					if(p[i+1] != '*'){
						vPrevNode.clear();
					}else{
						vPrevNode.insert(pCurrNode);
					}
					pCurrNode = pNode;
				}
			}else{
				// handle '*' case.
				pCurrNode->vConnectNodes.insert(pCurrNode); // add a link to itself.
				pCurrNode->bSelfLoop = true;
				vPrevNode.insert(pCurrNode);
			}
			i++;
		}

		Node* pNode = new Node;
		pNode->strPattern.assign("END"); // mark END
		pCurrNode->vConnectNodes.insert(pNode);
		for(std::set<Node*>::iterator it = vPrevNode.begin();
			it != vPrevNode.end();
			++it){
			(*it)->vConnectNodes.insert(pNode);
		}

		dumpCompiledPattern(&nodeGraph);
		return true;
	}

	void dumpCompiledPattern(Node* pNode){
		if(pNode->vConnectNodes.empty())
			std::cout << pNode->strPattern << std::endl;

		for(std::set<Node*>::iterator it = pNode->vConnectNodes.begin();
			it != pNode->vConnectNodes.end();
			++it){
			std::cout << pNode->strPattern << ",";
			if((*it) != pNode){
				std::cout << "--->" ;
				dumpCompiledPattern(*it);
			}
		}
		std::cout << std::endl;
	}

private:

	Node nodeGraph; // the START NODE;
};


int main(int argc, char** argv)
{
	Solution s;
	char pszString[] = "aaaaaaaaaa";
	char pszRegex[] = "a*";
	std::cout << pszRegex << (s.isMatch(pszString, pszRegex)? " " : " DOES NOT " ) << "Match " << pszString << std::endl;
	return 0;
}
