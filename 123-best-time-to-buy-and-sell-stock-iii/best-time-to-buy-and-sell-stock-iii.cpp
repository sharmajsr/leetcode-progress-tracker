class Solution {
public:
    int solve(vector<int>&prices,int idx,int buy,int cap,vector<vector<vector<int>>>&dp){
        if(cap == 0 or idx == prices.size() ) return 0;
        int profit = 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        if(buy){
            profit =  max(-prices[idx]+solve(prices,idx+1,0,cap,dp),solve(prices,idx+1,1,cap,dp));
        }else{
            profit =  max(prices[idx] + solve(prices,idx+1,1,cap-1,dp),solve(prices,idx+1,0,cap,dp));
        }
        return dp[idx][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        solve(prices,0,1,2,dp);
        return dp[0][1][2];
    }
};