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
    bool isSame(TreeNode* p, TreeNode* q) {
        if(!p and !q)   return true;
        if(!p || !q)    return false;
        if(p->val != q->val)    return false;
        return isSame(p->left,q->left) and isSame(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q)   return true;
        if(!p || !q )   return false;
        return p->val == q->val and isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }
};