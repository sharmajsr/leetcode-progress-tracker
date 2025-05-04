class Solution {
public:
    int solve(int idx,vector<int>&nums, vector<int>&dp){
        if(idx < 0 )    return 0;
        if(dp[idx] != -1)   return dp[idx];
        int pick = solve(idx-2,nums,dp) + nums[idx];
        int not_pick = solve(idx-1,nums,dp) ;
        return dp[idx] = max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums.size()-1,nums,dp);
    }
};