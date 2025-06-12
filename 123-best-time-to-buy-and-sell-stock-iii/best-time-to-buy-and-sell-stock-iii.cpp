class Solution {
public:
    int solve(vector<int>&prices,int idx,int buy,int transactions_left,vector<vector<vector<int>>>&dp){
        if(transactions_left == 0 )  return 0;
        if(idx == prices.size()){
            return 0;
        }

        if(dp[idx][buy][transactions_left] != -1) return dp[idx][buy][transactions_left];

        int profit = 0;

        if(buy){
            profit = max(-prices[idx]+solve(prices,idx+1,0,transactions_left,dp),solve(prices,idx+1,1,transactions_left,dp));
        }else{
            profit = max(prices[idx]+solve(prices,idx+1,1,transactions_left-1,dp),solve(prices,idx+1,0,transactions_left,dp));
        }

        return dp[idx][buy][transactions_left] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int  k= 2,n = prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k,-1)));
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,k,dp);
        
    }
};