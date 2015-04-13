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

private:
    bool m_bInit;
    int m_prev;
};

int main(int argc, char** argv){
	int A[] = {1};
	//int A[] = {1, 2, 5, 3, '#', '#', '#', 4, '#', 5, '#', 6};
	//int A[] = {1, 2, 3, 4, 5, 6, 7};
	Solution s;
	TreeNode tree(A, sizeof(A)/sizeof(int));
	tree.dump();
	vector<int> v(s.inorderTraversal(&tree));
	return 0;
}
