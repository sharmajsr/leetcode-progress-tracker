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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)   return {};
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*>qu;
            vector<int>temp;
            while(!q.empty()){
                auto top = q.front(); q.pop();
                temp.push_back(top->val);
                if(top->left) qu.push(top->left);
                if(top->right)qu.push(top->right);
            }
            q=qu;
            ans.push_back(temp);
        }
        return ans;
    }
};