/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector< vector<int> > ans (n,vector<int>(m,-1));
        
        int top = 0 ; 
        int left = 0;
        int bottom = n-1 ;
        int right = m-1;
        // cout<<bottom<<" "<<right<<endl;
        while( head and top<=bottom and left<=right){
            // cout<<head->val<<" "<<left<<" "<<right<<endl;
            for(int i=left;i<=right;i++){
                
                if(head){ 
                    // cout<<"First val "<<left << " "<< i<<" "<<right<<endl;
                    ans[top][i]=head->val;
                    head=head->next;
                }else{
                    // cout<<"First -1 "<<left << " "<< i<<" "<<right<<endl;
                    ans[top][i]=-1;
                }
            }
            ++top;
            if(!head) break;
            // --right;
            // cout<<head->val<<" "<<top<<" "<<bottom<<endl;
            for(int i=top;i<=bottom;i++){
                
                if(head){ 
                    // cout<<"second val"<<top << " "<< i<<" "<<bottom<<endl;
                    ans[i][right]=head->val;
                    head=head->next;
                }else{
                    // cout<<"second -1"<<top << " "<< i<<" "<<bottom<<endl;
                    ans[i][right]=-1;
                }
                
            }
            if(!head) break;
            --right;
            for(int i=right;i>=left;i--){
                
                if(head){ 
                    // cout<<"third val"<<right << " "<< i<<" "<<left<<endl;
                    ans[bottom][i]=head->val;
                    head=head->next;
                }else{
                    // cout<<"third -1 "<<right << " "<< i<<" "<<left<<endl;
                    ans[bottom][i]=-1;
                }
                
            }
            if(!head) break;
            --bottom;
            // ++top;
            for(int i=bottom;i>=top;i--){
                
                if(head){ 
                    // cout<<"fourth val"<<bottom << " "<< i<<" "<<top<<endl;
                    ans[i][left]=head->val;
                    head=head->next;
                }else{
                    // cout<<"fourth -1"<<bottom << " "<< i<<" "<<top<<endl;
                    ans[i][left]=-1;
                }
                
            }
            if(!head) break;
            ++left;
            // cout<<top<<" "<<bottom<<" "<<left<< " "<<right<<endl;

        }
        return ans;
    }
};