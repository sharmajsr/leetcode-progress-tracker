class Solution {
public:
    int solve(vector<int>&prices,int buy,int c,int idx,vector<vector<vector<int>>>&dp){
        // cout<<idx<<" "<<buy<<" "<<c<<endl;
        if(idx == prices.size()-1 ){
            if(buy == 1){
                return 0;
            }else{
                return prices[prices.size()-1];
            }
        }
        if(dp[idx][buy][c] != -1)   return dp[idx][buy][c];
        if(buy){
            if(c > 0 ){
                int get = -prices[idx] + solve(prices,0,1,idx+1,dp);
                int nget = solve(prices,1,1,idx+1,dp);
                // cout<<idx<<" "<<buy<<" "<<c<<" "<<get<<" "<<nget<<endl;
                return dp[idx][buy][c] = max(get,nget);
            }else{
                return dp[idx][buy][c] = solve(prices,1,1,idx+1,dp);
            }
        }else{
            return dp[idx][buy][c] = max(solve(prices,1,0,idx+1,dp)+prices[idx] , solve(prices,buy,1,idx+1,dp));
        }

    }
    int maxProfit(vector<int>& prices) {
        // reverse(prices.begin(),prices.end());
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices,1,1,0,dp);
    }
};