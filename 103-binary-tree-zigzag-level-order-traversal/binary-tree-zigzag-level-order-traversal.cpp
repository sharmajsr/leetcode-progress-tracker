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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)   return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        bool order = true;
        while(!q.empty()){
            queue<TreeNode*>qu;
            vector<int>temp;
            while(!q.empty()){
                auto fr = q.front();
                temp.push_back(fr->val);
                q.pop();
                if(fr->left ) qu.push(fr->left);
                if(fr->right ) qu.push(fr->right);
            }
            if(!order){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            
            order = !order;
            q = qu;

        }
        return ans;
    }
};