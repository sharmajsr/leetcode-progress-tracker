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
class FindElements {
public:
    unordered_map<int,int>um;
    void contaminateTree(TreeNode* root){
        if(root->left != NULL){
            // cout<<"inside left "<<root->val<<endl; 
            int val = 2*root->val+1;
            root->left->val = val;
            um[val]=1;
            contaminateTree(root->left);
        }
        if(root->right != NULL){
            // cout<<"inside right "<<root->val<<endl; 
            int val = 2*root->val+2;
            um[val]=1;
            root->right->val = val;
            contaminateTree(root->right);
        }
    }
    FindElements(TreeNode* root) {
        um.empty();
        root->val = 0 ;
        um[0]=1;
        contaminateTree(root);
    }
    
    bool find(int target) {
        if(um.find(target) != um.end()){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */