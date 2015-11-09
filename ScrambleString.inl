#include "common.h"

class StringTreeNode : public TreeNode {
public:
	StringTreeNode(char ch, bool bIsLeaf = false) : TreeNode(ch)
		, m_ch(ch)
		, m_bIsLeaf(bIsLeaf)
	{}

	StringTreeNode(bool bIsLeaf = false) : TreeNode(-1)
										 , m_bIsLeaf(bIsLeaf)
	{}

	void dump(){
		cout << "[";
		dump(this);
		cout << "]" << endl;
	}

	string toString(){
		string s;
		toStringImpl(this, s);
		return s;
	}

private:
	void dump(StringTreeNode* root){
		if (!root) return;
		dump(static_cast<StringTreeNode*>(root->left));
		if(root->m_bIsLeaf) cout << root->m_ch << ",";
		dump(static_cast<StringTreeNode*>(root->right));
	}

	void toStringImpl(StringTreeNode* root, string& s){
		if (!root) return;
		toStringImpl(static_cast<StringTreeNode*>(root->left), s);
		if (root->m_bIsLeaf) s.push_back(root->m_ch);
		toStringImpl(static_cast<StringTreeNode*>(root->right), s);
	}

public:
	bool m_bIsLeaf;
private:
	char m_ch;
};

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;

		if (s1 == s2)
			return true;

		if (!isIsomorphism(s1, s2)){
			return false;
		}

#if 0 // what a SB!
		for (int i = 1; i < s1.size(); ++i){
			for (size_t j = i; j < s2.size(); j++)
			{
				if ((isScramble(s1.substr(0, i), s2.substr(0, j)) && isScramble(s1.substr(i, s1.size()), s2.substr(j, s2.size()))) ||
					(isScramble(s1.substr(i, s1.size()), s2.substr(0, j)) && isScramble(s1.substr(i, s1.size()), s2.substr(0, j))))
					return true;
			}
		}
#endif
		for (int isep = 1; isep < s1.size(); ++isep){
			string seg11 = s1.substr(0, isep);
			string seg12 = s1.substr(isep);
			{//see if forward order is ok
				string seg21 = s2.substr(0, isep);
				string seg22 = s2.substr(isep);
				if (isScramble(seg11, seg21) && isScramble(seg12, seg22)) return true;
			}
			{//see if reverse order is ok
				string seg21 = s2.substr(s2.size() - isep);
				string seg22 = s2.substr(0, s2.size() - isep);
				if (isScramble(seg11, seg21) && isScramble(seg12, seg22)) return true;
			}

		}

		return false;
	}

	bool isIsomorphism(string& s1, string& s2){
		int eigen = 0;
		unordered_map<char, int> eigenMap;
		for (size_t i = 0; i < s1.size(); i++)
		{
			eigen++;
			if (eigenMap.find(s1[i]) == eigenMap.end())
				eigenMap[s1[i]] = 1;
			else
				eigenMap[s1[i]]++;
		}

		for (size_t i = 0; i < s2.size(); i++)
		{
			if (eigenMap.find(s2[i]) == eigenMap.end())
				return false;
			else{
				if (eigenMap[s2[i]]--){
					eigen--;
				}
			}
		}

		return !eigen;
	}



	bool isScramble_WRONG(string s1, string s2) {
		vector<StringTreeNode*> vPartitionTree;
		generatePartitionTrees(s1, vPartitionTree);

		for (size_t i = 0; i < vPartitionTree.size(); i++)
		{
			if (checkScramble(vPartitionTree[i], s2))
				return true;
		}
		return false;
	}

	bool checkScramble(StringTreeNode* root, string& s){
		return checkScrambleImpl(root, root, s);
	}

	bool checkScrambleImpl(StringTreeNode* root, StringTreeNode* pCurrNode, string s){
		// HOW to impl the permutation of the swap?????????????????????
		// HOW ????????????????????????????????????????????????????????
	}
	

	void generatePartitionTrees(string& s, vector<StringTreeNode*>& vPartitionTree){
		if (s.empty())
			return;

		if (s.size() == 1){
			vPartitionTree.push_back(new StringTreeNode(s[0], true));
			return;
		}

		if (s.size() == 2){
			StringTreeNode* pRoot = new StringTreeNode;
			pRoot->left = new StringTreeNode(s[0], true);
			pRoot->right = new StringTreeNode(s[1], true);
			vPartitionTree.push_back(pRoot);
			return;
		}

		vector<StringTreeNode*> vSubLtTree;
		vector<StringTreeNode*> vSubRtTree;
		for (int i = 1; i < s.size(); ++i){
			generatePartitionTrees(string(s.begin(), s.begin() + i), vSubLtTree);
			generatePartitionTrees(string(s.begin() + i, s.end()), vSubRtTree);

			for (size_t j = 0; j < vSubLtTree.size(); j++)
			{
				for (size_t k = 0; k < vSubRtTree.size(); k++)
				{
					StringTreeNode* pRoot = new StringTreeNode;
					pRoot->left = vSubLtTree[j];
					pRoot->right = vSubRtTree[k];
					vPartitionTree.push_back(pRoot);
				}
			}
			vSubLtTree.clear();
			vSubRtTree.clear();
		}
	}
};


int main(int argc, char** argv){
	Solution s;
#if 0
	vector<StringTreeNode*> vTrees;
	s.generatePartitionTrees(string("greate"), vTrees);

	cout << "Total " << vTrees.size() << " trees." << endl;
	for (size_t i = 0; i < vTrees.size(); i++)
	{
		cout << vTrees[i]->toString() << endl;
	}
#endif
	cout << (s.isScramble(string("xstjzkfpkggnhjzkpfjoguxvkbuopi"), string("xbouipkvxugojfpkzjhnggkpfkzjts")) ? "YES" : "NO") << endl;
	return 0;
}