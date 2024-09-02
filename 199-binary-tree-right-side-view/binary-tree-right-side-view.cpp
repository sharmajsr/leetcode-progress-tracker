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
        vector<int> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            // auto it = q.front();
            // q.pop();
            vector<int>temp;
            queue<TreeNode*>qu;
            while(!q.empty()){
                TreeNode* it = q.front();
                q.pop();
                if(it)  temp.push_back(it->val);
                
                if(it->left !=NULL)    qu.push(it->left);
                if(it->right !=NULL)  qu.push(it->right);
            }
            int val = temp[temp.size()-1];
            cout<<temp.size()<<" "<<val<<endl;
            ans.push_back(val);
            q =qu;
        }
        return ans;
    }
};