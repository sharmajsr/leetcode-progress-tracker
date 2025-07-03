class Solution {
public:
    int solve(vector<int>&prices, int buy, int idx,vector<vector<int>>&dp){
        if(idx == prices.size())   {
            return 0;
        }
        if(dp[idx][buy] != -1)  return dp[idx][buy];
        if(buy){
            return dp[idx][buy] = max( solve(prices,1,idx+1,dp), -prices[idx] + solve(prices,0,idx+1,dp));
        }else{
            return dp[idx][buy] = max(prices[idx] + solve(prices,1,idx+1,dp), solve(prices,0,idx+1,dp)) ;
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,1,0,dp);
    }
};