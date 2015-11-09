#include "common.h"
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(NULL == root)
            return true;
        
        m_bInit = false;
        m_prev = INT_MIN;
        return traversal(root);        
    }
    
    bool traversal(TreeNode* root){
        int lastVal = 0;
        bool ret = true;
        if(root->left)
            ret &= traversal(root->left);
        
        if(m_bInit && m_prev >= root->val)
            return false;

        m_bInit = true;
        m_prev = root->val;
        if(ret && root->right)
            ret &= traversal(root->right);

        return ret;
    }

	vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
		if(root){
			inorderTraversalImplRecursive(root, v);
			printContainer<vector<int> >(v, v.size(), "v1");

			v = inorderTraversalImplIterative(root);
			printContainer<vector<int> >(v, v.size(), "v2");
		}
		return v;
    }

	void inorderTraversalImplRecursive(TreeNode *root, vector<int>& v) {
		if(!root)
			return;
		if(root->left)
			inorderTraversalImplRecursive(root->left, v);
		v.push_back(root->val);
		if(root->right)
			inorderTraversalImplRecursive(root->right, v);
	}

	vector<int> inorderTraversalImplIterative(TreeNode *root) {
        vector<int> v;
		list<TreeNode*> nodeQueue;
		list<TreeNode*> nodeVisit;
		nodeQueue.push_back(root);
		while(!nodeQueue.empty() || !nodeVisit.empty()){
			TreeNode* p = NULL;
			if(!nodeQueue.empty()){
				p = nodeQueue.front();
				nodeQueue.pop_front();
				nodeVisit.push_back(p);
			}

			if(p && p->left){
				nodeQueue.push_back(p->left);
			}else{
				//cout << nodeVisit.back() << endl;
				TreeNode* p1 = nodeVisit.back();
				nodeVisit.pop_back();
				v.push_back(p1->val);
				if(p1->right)
					nodeQueue.push_back(p1->right);
			}
		}
		
		return v;
	}

	vector<int> preorderTraversal(TreeNode* root) {
		if (!root)
			return vector<int>();

		vector<int> preOrderNodes;
		std::stack<TreeNode*> nodeStack;
		nodeStack.push(root);
		while (!nodeStack.empty()){
			TreeNode* pNode = nodeStack.top();
			nodeStack.pop();
			preOrderNodes.push_back(pNode->val);
			if(pNode->right) nodeStack.push(pNode->right);
			if(pNode->left) nodeStack.push(pNode->left);
		}

		return preOrderNodes;
	}

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (NULL == root)
			return vector<vector<int>>();

		bool bforward = false;
		list<TreeNode*> stackUpNode(1, root);
		list<TreeNode*> stackLoNode;

		vector<vector<int>> outputOrder(1, vector<int>(1, root->val));
		vector<int> vLvNums;
		while (!stackUpNode.empty()){
			TreeNode* pNode = NULL;
			pNode = stackUpNode.front();
			stackUpNode.pop_front();
			if (pNode->left) stackLoNode.push_back(pNode->left);
			if (pNode->right) stackLoNode.push_back(pNode->right);

			if (stackUpNode.empty()){
				if (bforward){
					list<TreeNode*>::const_iterator rIt = stackLoNode.begin();
					while (rIt != stackLoNode.end()){
						vLvNums.push_back((*rIt)->val);
						++rIt;
					}
				}
				else{
					list<TreeNode*>::reverse_iterator rIt = stackLoNode.rbegin();
					while (rIt != stackLoNode.rend()){
						vLvNums.push_back((*rIt)->val);
						++rIt;
					}
				}

				if(!vLvNums.empty()) outputOrder.push_back(vLvNums);
				bforward = !bforward;
				std::swap(stackUpNode, stackLoNode);
				vLvNums.clear();
			}
		}

		return outputOrder;
	}

private:
    bool m_bInit;
    int m_prev;
};

int main(int argc, char** argv){
	int A[] = { 3 };
	//int A[] = { 3, 9, 20, '#', 22, 15, 7 };
	//int A[] = {1, 2, 5, 3, '#', '#', '#', 4, '#', 5, '#', 6};
	//int A[] = {1, 2, 3, 4, 5, 6, 7};
	Solution s;
	TreeNode tree(A, sizeof(A)/sizeof(int));
	tree.dump();
	vector<int> v1(s.inorderTraversal(&tree));
	vector<int> v2(s.preorderTraversal(&tree));
	//printContainer<vector<int>>(v2, v2.size());

	pfcout << "----------------------------------------";
	vector<vector<int>> v3 = s.zigzagLevelOrder(&tree);
	for (size_t i = 0; i < v3.size(); i++)
	{
		printContainer<vector<int>>(v3[i], v3[i].size());
	}
	return 0;
}
