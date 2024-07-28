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
    int solve(TreeNode* node,TreeNode *parent, int &ans){
        if(!node)   return 0 ;

        int left = solve(node->left,node,ans);
        int right = solve(node->right,node,ans);

        if( parent->val % 2 == 0 ){
            ans += left +right;
        }
        return node->val;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans;
        solve(root->left,root,ans);
        solve(root->right,root,ans);
        return ans;

    }
};