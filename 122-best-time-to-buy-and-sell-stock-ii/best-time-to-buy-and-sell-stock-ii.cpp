class Solution {
public:
    int solve(int idx,int buy,vector<int>& prices,vector<vector<int>>&dp){
        if(idx == prices.size() )   return 0;
        int profit = 0; 
        if(dp[idx][buy] != -1)  return dp[idx][buy];
        if(buy){
            profit = max(-prices[idx] + solve(idx+1,0,prices,dp), solve(idx+1,1,prices,dp));
        }else{
            profit = max(prices[idx] + solve(idx+1,1,prices,dp),solve(idx+1,0,prices,dp));
        }
        return dp[idx][buy]= profit;
    }

    int maxProfit(vector<int>& prices) {
        int ans = 0 , n = prices.size();
        // for(int i=0 ; i<n-1 ; i++){
        //     if(prices[i] < prices[i+1]){
        //         ans += prices[i+1]-prices[i];
        //     }
        // }
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        for(int i= n;i >=0 ;i--){
            for(int j=0;j<=1;j++){
                if(i == n){
                    dp[i][j] = 0 ;
                    continue;
                }
                int profit = 0 ;
                if( j == 1 ){
                    profit = max(-prices[i]+dp[i+1][0] , dp[i+1][1]);
                }else{
                    profit = max(prices[i] + dp[i+1][1] , dp[i+1][0]);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
        // return solve(0,1,prices,dp);
        // return ans;
    }
};