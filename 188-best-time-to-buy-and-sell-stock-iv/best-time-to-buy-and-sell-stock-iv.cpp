class Solution {
public:
    int solve(vector<int>&prices,int idx,int buy,int cap,vector<vector<vector<int>>>&dp){
        if( idx == prices.size() or cap == 0)   return 0;
        int profit ;
        if(dp[idx][buy][cap] != -1)   return dp[idx][buy][cap];
        if(buy){
            profit = max( -prices[idx] + solve(prices,idx+1,0,cap,dp),solve(prices,idx+1,1,cap,dp));
        }else{
            profit = max( prices[idx] + solve(prices,idx+1,1,cap-1,dp),solve(prices,idx+1,0,cap,dp));
        }
        return dp[idx][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        solve(prices,0,1,k,dp);
        return dp[0][1][k];
    }
};