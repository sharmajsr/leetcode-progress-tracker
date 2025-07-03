class Solution {
public:
    int solve(vector<int>&prices, int buy, int idx,vector<vector<int>>&dp,int c){

        if(idx == prices.size()){
            return 0;
        }

        if(dp[idx][buy] != -1)  return dp[idx][buy];

        if(buy){
            int not_take = solve(prices,1,idx+1,dp,1);
            int take = 0;
            if(c == 1){
                take = -prices[idx] + solve(prices,0,idx+1,dp,1); 
            }
            return dp[idx][buy] = max( take, not_take );
        }else{
            return dp[idx][buy]= max(prices[idx] + solve(prices,1,idx+1,dp,0), solve(prices,0,idx+1,dp,1)) ;
        }
    }

    int solve(vector<int>&prices, int buy, int idx,vector<vector<vector<int>>>&dp,int c){

        if(idx == prices.size()){
            return 0;
        }

        if(dp[idx][buy][c] != -1)  return dp[idx][buy][c];

        if(buy){
            int not_take = solve(prices,1,idx+1,dp,1);
            int take = 0;
            if(c == 1){
                take = -prices[idx] + solve(prices,0,idx+1,dp,1); 
            }
            return dp[idx][buy][c] = max( take, not_take );
        }else{
            return dp[idx][buy][c] = max(prices[idx] + solve(prices,1,idx+1,dp,0), solve(prices,0,idx+1,dp,c)) ;
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices,1,0,dp,1);
    }
};