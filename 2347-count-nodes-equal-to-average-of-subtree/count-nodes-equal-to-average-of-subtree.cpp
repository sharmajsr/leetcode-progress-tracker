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
    pair<int,int> solve(TreeNode* root,int &cnt){
        if(!root)   return  {0,0};
        
        auto [leftSum,NumberOfElementsInLeft] = solve(root->left,cnt);
        auto [rightSum,NumberOfElementsInright]  = solve(root->right,cnt);
        int totalElementInSubtree = NumberOfElementsInLeft+NumberOfElementsInright+1;
        int totalSumInSubtree = leftSum+ rightSum+root->val;
        int avg;
        if(totalElementInSubtree != 0){
            avg = totalSumInSubtree/totalElementInSubtree;
        }else{
            avg =0;
        }
        if( avg == root->val){
            ++cnt;
        }
        return { leftSum +rightSum + root->val ,NumberOfElementsInLeft + NumberOfElementsInright + 1 };

    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0 ;
        solve(root,cnt);
        return cnt;
    }
};