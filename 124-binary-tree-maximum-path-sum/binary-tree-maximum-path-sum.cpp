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
    int solve(TreeNode* root,int &maxi){

        if(!root)   return 0;

        int left = solve(root->left,maxi);
        int right = solve(root->right,maxi);

        maxi = max(left + right + root->val , maxi);
        int t1 = max(left+root->val,right + root->val);
        int t2 = max(t1,root->val);
        maxi = max(maxi,t2);
        return max( root->val + max(left,right), root->val);

    }
    int maxPathSum(TreeNode* root) {
        int maxi = -1002 ;
        solve(root,maxi);
        return maxi;
    }
};