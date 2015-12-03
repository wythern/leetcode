#include "common.h"

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		unordered_map<int, unordered_set<int>> connections;
		for (size_t i = 0; i < n; i++)
		{
			connections[i] = unordered_set<int>();
		}

		for (size_t i = 0; i < edges.size(); i++)
		{
			connections[edges[i].first].insert(edges[i].second);
			connections[edges[i].second].insert(edges[i].first);
		}

		while (connections.size() > 2){
			vector<int> leaves;
			for (unordered_map<int, unordered_set<int>>::iterator it = connections.begin();
				it != connections.end(); ++it)
			{
				if (it->second.size() == 1)
				{
					leaves.push_back(it->first);
				}
			}

			while (!leaves.empty())
			{
				int leaf = leaves.back();
				for (unordered_set<int>::iterator it = connections[leaf].begin();
					it != connections[leaf].end(); ++it)
				{
					connections[*it].erase(leaf);
				}
				connections.erase(leaf);
				leaves.pop_back();
			}
		}

		vector<int> vMHTRoots;
		unordered_map<int, unordered_set<int>>::iterator it = connections.begin();
		vMHTRoots.push_back(it->first);
		++it;
		if (it != connections.end())
			vMHTRoots.push_back(it->first);

		return vMHTRoots;
	}
};

int main(int argc, char** argv){
	Solution s;
	int A[][2] = {
		//{ 1, 0 }, { 1, 2 }, { 1, 3 },
		{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}
	};

	vector<pair<int, int> > links;
	for (size_t i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	{
		links.push_back(pair<int, int>(A[i][0], A[i][1]));
	}
	s.findMinHeightTrees(4, links);

	return 0;
}

