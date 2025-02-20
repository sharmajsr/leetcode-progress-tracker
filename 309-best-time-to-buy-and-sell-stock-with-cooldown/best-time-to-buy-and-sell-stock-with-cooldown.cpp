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
        int n = prices.size();
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
        // solve(prices,0,1,1,dp);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if( j == 1 ){
                    dp[i][j]= max( -prices[i] + dp[i+1][0], dp[i+1][1]);
                }else{
                    // int s1 = 
                    dp[i][j] = max( prices[i] + dp[i+2][1] , dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};