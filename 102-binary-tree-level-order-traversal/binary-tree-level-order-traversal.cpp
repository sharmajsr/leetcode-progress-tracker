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
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*>qu;
            vector<int>temp;
            while(!q.empty()){
                auto front = q.front();
                temp.push_back(front->val);
                q.pop();
                if(front->left) qu.push(front->left);
                if(front->right)    qu.push(front->right);
            }
            ans.push_back(temp);
            q=qu;
        }
        return ans;
    }
};