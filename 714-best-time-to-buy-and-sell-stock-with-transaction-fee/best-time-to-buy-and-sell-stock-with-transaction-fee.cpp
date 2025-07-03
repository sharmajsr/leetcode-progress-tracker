class Solution {
public:
    int solve(vector<int>&prices, int buy, int idx,vector<vector<int>>&dp,int fee){

        if(idx == prices.size()){
            return 0;
        }

        if(dp[idx][buy] != -1)  return dp[idx][buy];

        if(buy){
            int not_take = solve(prices,1,idx+1,dp,fee);
            int take = 0;
            // if(c == 1){
                take = -prices[idx] + solve(prices,0,idx+1,dp,fee); 
            // }
            return dp[idx][buy] = max( take, not_take );
        }else{
            return dp[idx][buy] = max(prices[idx] + solve(prices,1,idx+1,dp,fee) -fee, solve(prices,0,idx+1,dp,fee)) ;
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,1,0,dp,fee);
    }
};