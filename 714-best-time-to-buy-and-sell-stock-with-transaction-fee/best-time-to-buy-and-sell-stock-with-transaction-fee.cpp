class Solution {
public:
    int solve(vector<int>&prices,int idx,int buy,int fee,vector<vector<int>>&dp){
        if( idx == prices.size())   return 0;
        if(dp[idx][buy] != -1)  return dp[idx][buy];
        if(buy){
            return dp[idx][buy] = max( -prices[idx] + solve(prices,idx+1,0,fee,dp),solve(prices,idx+1,1,fee,dp));
        }else{
            return dp[idx][buy] = max( prices[idx] -fee + solve(prices,idx+1,1,fee,dp),solve(prices,idx+1,0,fee,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        solve(prices,0,1,fee,dp);
        return dp[0][1];
    }
};