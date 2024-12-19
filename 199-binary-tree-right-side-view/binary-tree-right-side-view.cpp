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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            vector<int>temp;
            queue<TreeNode*>qu;
            while(!q.empty()){
                auto curr = q.front();
                q.pop();
                if(curr) temp.push_back(curr->val);
                if(curr->left != NULL){
                    qu.push(curr->left);
                }
                if(curr->right != NULL){
                    qu.push(curr->right);
                }
            }
            q=qu;
            ans.push_back(temp[temp.size()-1]);
        }

        return ans;
    }
};