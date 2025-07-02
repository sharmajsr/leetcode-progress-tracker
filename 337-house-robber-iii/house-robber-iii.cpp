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
    int solve(TreeNode* root,int last,unordered_map<TreeNode*,int>um[2]){
        if(!root)   return 0;

        int take = 0,not_take = 0 ;
        if (um[last].count(root))
            return um[last][root];
        if(last){
            take = root->val + solve(root->left,0,um) + solve(root->right,0,um);
            not_take = solve(root->left,1,um) + solve(root->right,1,um);
            
        }else{
            not_take = solve(root->left,1,um) + solve(root->right,1,um);
        }
        return um[last][root] = max(take,not_take);
    }
    int rob(TreeNode* root) {
        if(!root)   return 0;
        unordered_map<TreeNode*,int>um[2];

        int m2 = solve(root,1,um);
        um[0][root] = root->val;
        int m1  = root->val + solve(root->left,0,um) + + solve(root->right,0,um);
        

        return max(m1,m2);
    }
};