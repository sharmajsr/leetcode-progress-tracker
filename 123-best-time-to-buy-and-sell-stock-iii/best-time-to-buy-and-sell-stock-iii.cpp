class Solution {
public:
    int solve(vector<int>&prices, int idx, int buy, vector<vector<vector<int>>>&dp,int cnt){
        if(cnt == 0){
            return 0;
        }
        if(idx == prices.size()){
            return 0;
        }
        if(dp[idx][buy][cnt] != -1 ){
            return dp[idx][buy][cnt];
        }
        if(buy){ 
            return dp[idx][buy][cnt] = max( -prices[idx] + solve(prices,idx+1, 0,dp ,cnt) , solve(prices, idx+1,1,dp,cnt));
        }else{
            return dp[idx][buy][cnt] = max( prices[idx] + solve(prices,idx+1,1,dp,cnt-1), solve(prices, idx+1,0,dp,cnt));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k =2 ;

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,dp,k);
    }
};