class Solution {
public:
     int solve(vector<int>&coins, int amount, int idx, vector<vector<int>>&dp){
        if(amount == 0 ){
            return dp[idx][amount] = 1 ;
        }
        if(idx == 0 ){
            if(amount%coins[idx] == 0 ){
                return dp[idx][amount] = 1;
            }
            return 0;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int not_take = solve(coins , amount , idx-1, dp);
        int take = 0, minTake = 1e9;
        if(amount>= coins[idx]){
            take = solve(coins,amount - coins[idx] , idx, dp);
        }
        return dp[idx][amount] = take + not_take;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        solve(coins,amount, n-1 , dp);
        // if(dp[n-1][amount] == 1e9){
        //     return -1;
        // }
        return dp[n-1][amount] == -1 ? 0 :  dp[n-1][amount] ;
    }
};