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
        int n = prices.size();
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        // solve(prices,0,1,fee,dp);
        for(int i=n-1;i>=0 ;i--){
            for(int j=0;j<2;j++){
                if( j==1 ){
                    dp[i][j] = max(-prices[i] + dp[i+1][0],dp[i+1][1]);
                }else{
                    dp[i][j] = max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};