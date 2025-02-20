class Solution {
public:
    int solve(vector<int>&prices,int idx,int buy,int cooldown,vector<vector<int>>&dp){
        if( idx >= prices.size())       return 0;
        if( dp[idx][buy] != -1 )        return dp[idx][buy];
        if(buy){
            return dp[idx][buy]= max(-prices[idx] + solve(prices,idx+1,0,cooldown,dp),solve(prices,idx+1,1,cooldown,dp));
        }else{
            return dp[idx][buy]= max(prices[idx] + solve(prices,idx+1+cooldown,1,cooldown,dp),solve(prices,idx+1,0,cooldown,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        solve(prices,0,1,1,dp);
        return dp[0][1];
    }
};