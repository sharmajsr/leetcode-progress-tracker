class Solution {
public:
    int solve(vector<int>&prices, int buy, int idx,vector<vector<vector<int>>>&dp,int k){

        if(k == 0 ){
            return 0;
        }

        if(idx == prices.size()){
            return 0;
        }

        if(dp[idx][buy][k] != -1)  return dp[idx][buy][k];

        if(buy){
            return dp[idx][buy][k] = max( solve(prices,1,idx+1,dp,k), -prices[idx] + solve(prices,0,idx+1,dp,k));
        }else{
            return dp[idx][buy][k] = max(prices[idx] + solve(prices,1,idx+1,dp,k-1), solve(prices,0,idx+1,dp,k)) ;
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,1,0,dp,k);
    }
};