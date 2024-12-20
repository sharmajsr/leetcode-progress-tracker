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
    TreeNode* reverseOddLevels(TreeNode* root) {
        // TreeNode* dummyRoot
        int level = 0 ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*>qu;
            vector<int>tempv;
            stack<TreeNode*>temps;
            while(!q.empty()){
                auto it =q.front();
                q.pop();
                tempv.push_back(it->val);
                temps.push(it);
                if(it->left)    qu.push(it->left);
                if(it->right)    qu.push(it->right);

            }
            if(level & 1){ 
                for(auto i : tempv){
                    auto top = temps.top();
                    temps.pop();
                    top->val = i;
                }
            }
            ++level;
            q = qu;
        }
        return root;
    }
};