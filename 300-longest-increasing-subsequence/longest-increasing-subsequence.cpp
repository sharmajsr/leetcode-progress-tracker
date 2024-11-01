class Solution {
public:
    void solve(vector<int>nums,vector<int>cur,int &ans){
        // cout<<nums.size()<<" "<<cur.size()<< " <<- ";
        if(nums.size() == 0 ){
            if(cur.size() > ans)    ans = cur.size();
            return;
        }
        // cout<<" ->"<<nums.size()<<" "<<cur.size()<<endl;
        // for(auto i: cur)    cout<<i<<" ";
        // cout<<endl;
        vector<int>op1, op2;
        op1 = cur;
        op2 = cur;
        int firstElement = nums[0];
        // nums.pop_back();
        nums.erase(nums.begin());
        solve(nums,op1,ans);
        
        if( op2.size() == 0 ){
            op2.push_back(firstElement);
            // cout<<"when op2 size is zero "<<firstElement<<endl;
            solve(nums,op2,ans);
        }else if(op2.size() > 0 and op2[op2.size()-1] < firstElement){
            // cout<<"when op2 size has elements "<<op2.size()<<endl;
            op2.push_back(firstElement);
            solve(nums,op2,ans);
        }
    } 
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() , ans = 1 ;
        vector<int>lis(n,1);
        for(int i=0 ; i<n ; i++){
            for(int j=0;j<i;j++){
                if(nums[j] >= nums[i])  continue;
                else lis[i] = max(lis[i] , 1+ lis[j]);
                ans = max(ans,lis[i]);
            }
        }
        return ans;
    }
};