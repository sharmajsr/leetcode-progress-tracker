class Solution {
public:
    int solve(vector<int>&nums,int idx,vector<int>&dp){
        if(idx<0)   return 0;
        if(idx == 0){
            return dp[idx] = nums[idx];
        } 
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = max(solve(nums,idx-1,dp),solve(nums,idx-2,dp)+nums[idx]);

    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,nums.size()-1,dp);
    }
};