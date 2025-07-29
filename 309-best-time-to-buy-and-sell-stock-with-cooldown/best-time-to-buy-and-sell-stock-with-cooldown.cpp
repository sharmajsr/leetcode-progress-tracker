class Solution {
public:
vector<vector<int>>dp;
    int solve(vector<int>&prices, int idx,int buy){
        if(idx >= prices.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1)    return dp[idx][buy];

        int profit = 0 ;

        if(buy){
            profit = max(-prices[idx] + solve(prices, idx+1, 0 ) , solve(prices,idx+1,1) ) ;
        }else{
            profit = max(prices[idx] + solve(prices, idx+2, 1 ) , solve(prices,idx+1,0)) ;
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        
        dp.resize(prices.size() , vector<int>(2,-1));
        return solve(prices,0,1);
    }
};