class Solution {
public:
    int solve(vector<int>&nums,int n,vector<int>& dp){
        if(n== 0)   return  dp[n] = nums[0];
        if( n<0)    return 0;
        if(dp[n]!=-1)   return dp[n];

        int curr = nums[n]+ solve(nums,n-2,dp);
        int prev = solve(nums,n-1,dp);

        return dp[n] = max(curr,prev);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        solve(nums,nums.size()-1,dp);
        return dp[nums.size()-1];

    }
};