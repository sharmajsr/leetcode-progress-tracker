class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n<=2)    return dp[n] = n;
        if(dp[n] != -1 ) return dp[n];
        else return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(50,-1);
        return solve(n,dp);
    }
};