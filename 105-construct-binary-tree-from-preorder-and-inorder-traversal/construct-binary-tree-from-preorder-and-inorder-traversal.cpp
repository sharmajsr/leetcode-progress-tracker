/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
map<int,int>ind;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int preStart, int preEnd, int inStart ,int inEnd){
        if(preStart > preEnd or inStart > inEnd ){
            return NULL;
        }
        int top = preorder[preStart];
        int idx = ind[top];
        int numsLeft = idx - inStart;
        TreeNode* newRoot = new TreeNode(top);
        newRoot->left = solve(preorder,inorder,preStart+1,preStart + numsLeft , inStart,idx-1);
        newRoot->right = solve(preorder,inorder,preStart+numsLeft+1,preEnd , idx+1,inEnd);
        return newRoot;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i= 0 ;i < inorder.size() ;i++){
            ind[inorder[i]]=i;
        }
        return solve(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};