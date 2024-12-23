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
    int cnt1;
    static bool cmp(const int &a,const int &b){
        if(a<b) return true;
        else{
            // cnt1+=1;
            return false;
        }
    }
    // int findOperationsToSort(vector<int>in){
    //     cnt1= 0;
    //     sort(in.begin,in.end(),cmp);
    //     return cnt1;
    // }
    int minimumOperations(TreeNode* root) {
        int ans = 0 ,cnt1 = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            queue<TreeNode*>qu;
            map<int,int>mp;
            while(!q.empty()){
                auto top =q.front();
                
                q.pop();
                if(top->left){
                    qu.push(top->left);
                    mp[top->left->val] = temp.size();
                    temp.push_back(top->left->val);
                }   
                if(top->right){
                    qu.push(top->right);
                    mp[top->right->val] = temp.size();
                    temp.push_back(top->right->val);
                }  
            }
            sort(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++){
                int orglIdx = mp[temp[i]];
                if( orglIdx != i){
                    swap(temp[i],temp[orglIdx]);
                    ans++;
                    --i;
                }
            }
            q = qu;
            // ans += findOperationsToSort(temp);
        }

        return ans;
    }
};