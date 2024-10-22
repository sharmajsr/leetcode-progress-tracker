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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long ans;
        priority_queue<long long>maxHeap;
        vector<long long >ve;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            // auto fr = q.front();
            // q.pop();
            queue<TreeNode*>qu;
            long long curLevelSum = 0;
            while(!q.empty()){
                auto fr = q.front();
                q.pop();
                curLevelSum += fr->val;
                if(fr->left)    qu.push(fr->left);
                if(fr->right)   qu.push(fr->right);
            }
            maxHeap.push(curLevelSum);
            q=qu;
        }
        while(!maxHeap.empty() and k-- and k>0){
            maxHeap.pop();
        }
        return maxHeap.empty() ? -1 : maxHeap.top();
    }
};

//  2 4 6 8 10