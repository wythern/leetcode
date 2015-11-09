#include "common.h"

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		DirectedGraph g(numCourses, prerequisites);
		return !g.hasCycle();
	}

	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		DirectedGraph g(numCourses, prerequisites);
		return g.topologicalSort(g);
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[][2] = {
//		{ 0, 1 }, { 1, 5 },
//		{ 1, 3 }, { 1, 4 },
//		{ 3, 4 }, { 2, 1 },
		{ 3, 5 }, 
	};

	vector<pair<int, int> > links;
	for (size_t i = 0; i < sizeof(A)/sizeof(A[0]); i++)
	{
		links.push_back(pair<int, int>(A[i][0], A[i][1]));
	}

	//cout << (s.canFinish(links.size(), links) ? "Can " : "Can not ") << "finish" << endl;
	//DirectedGraph g(1, vector<pair<int, int> >());
	DirectedGraph g(6, links);
	g.dump();
	vector<int> vId = g.topologicalSort(g);
	printContainer<vector<int>>(vId, vId.size());
	return 0;
}