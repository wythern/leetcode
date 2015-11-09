#include "common.h"

/**
* Definition for undirected graph.
* struct UndirectedGraphNode {
*     int label;
*     vector<UndirectedGraphNode *> neighbors;
*     UndirectedGraphNode(int x) : label(x) {};
* };
*/
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (NULL == node)
			return NULL;
		map<int, UndirectedGraphNode *> setVisited;
		return cloneGraphImpl(node, setVisited);
	}

	UndirectedGraphNode *cloneGraphImpl(UndirectedGraphNode *node, map<int, UndirectedGraphNode*>& setVisited){
		UndirectedGraphNode* pNode = new UndirectedGraphNode(node->label);
		setVisited[node->label] = pNode;

		for (size_t i = 0; i < node->neighbors.size(); i++)
		{
			if (setVisited.find(node->neighbors[i]->label) == setVisited.end()){
				UndirectedGraphNode* pNeibNode = cloneGraphImpl(node->neighbors[i], setVisited);
				pNode->neighbors.push_back(pNeibNode);
			}
			else{
				pNode->neighbors.push_back(setVisited[node->neighbors[i]->label]);
			}
		}

		return pNode;
	}
};

void main(){
	UndirectedGraphNode* graph1 = UndirectedGraphNode::from("0,1,");
	string strGraph = graph1->serialize();
	cout << strGraph << endl;
	Solution s;
	UndirectedGraphNode* graph2 = s.cloneGraph(graph1);
	strGraph = graph2->serialize();
	cout << strGraph << endl;
	//UndirectedGraphNode::isEqual(graph1, graph2);
}