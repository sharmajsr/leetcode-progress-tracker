class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>op,int target, vector<int>&nums,int idx){
        if(target == 0 ){
            ans.push_back(op);
            return ;
        }
        
        if( target < 0 or idx >= nums.size() ) return ;
        cout<<idx<<endl;
        solve(ans,op,target,nums,idx+1);
        op.push_back(nums[idx]);
        solve(ans,op,target-nums[idx],nums,idx);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        solve(ans,{},target,candidates,0);
        return ans;

    }
};