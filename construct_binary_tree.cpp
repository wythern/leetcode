#include "common.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeImpl(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    TreeNode* buildTreeImpl(vector<int>::iterator preBegin, vector<int>::iterator preEnd,
                            vector<int>::iterator inBegin, vector<int>::iterator inEnd){
        if(preBegin == preEnd || inBegin == inEnd)
            return NULL;

        TreeNode* pNode = new TreeNode(*preBegin);
        vector<int>::iterator itInorder = inBegin;
        while(*itInorder != *preBegin && itInorder != inEnd){
            ++itInorder;
        }

        int step =  distance(inBegin, itInorder);
        pNode->left = buildTreeImpl(preBegin + 1, preBegin + 1 + step, inBegin, itInorder);
        pNode->right = buildTreeImpl(preBegin + 1 + step, preEnd, itInorder + 1, inEnd);
             
        return pNode;
    }

    TreeNode* buildTree_vector(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.empty() || preorder.empty())
            return NULL;

        TreeNode* pNode = new TreeNode(inorder.front());
        vector<int>::iterator itPreorder = preorder.begin();
        while(*itPreorder != preorder.front()){
            ++itPreorder;
        }
        vector<int> preorderLeft(preorder.begin(), itPreorder);
        vector<int> preorderRight(itPreorder, preorder.end());
        
        vector<int> inorderLeft(inorder.begin() + 1, inorder.begin() + 1 + preorderLeft.size());
        vector<int> inorderRight(inorder.begin() + 1 + preorderLeft.size(), inorder.end());
        
        pNode->left = buildTree(preorderLeft, inorderLeft);
        pNode->right = buildTree(preorderRight, inorderRight);
        
        return pNode;
    }
};

int main(int argc, char** argv){
	Solution s;
	int A[] = {1, 2, 3, 4, 5};
    int B[] = {3, 2, 4, 1, 5};
    vector<int> vA(A, A+5);
    vector<int> vB(B, B+5);
    TreeNode* pTree = s.buildTree(vA, vB);
    pTree->dump();
	return 0;
}
