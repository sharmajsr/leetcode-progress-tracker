class Solution {
public:
    int solve(vector<int>&coins, int amount, int idx, vector<vector<int>>&dp){
        if(amount == 0 ){
            return dp[idx][amount] = 0 ;
        }
        if(idx == 0 ){
            if(amount%coins[idx] == 0 ){
                return dp[idx][amount] = amount/coins[idx];
            }
            return 1e9;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int not_take = solve(coins , amount , idx-1, dp);
        int take = INT_MAX, minTake = 1e9;
        if(amount>= coins[idx]){
            take = 1+ solve(coins,amount - coins[idx] , idx, dp);
        }
        return dp[idx][amount] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        solve(coins,amount, n-1 , dp);
        if(dp[n-1][amount] == 1e9){
            return -1;
        }
        return dp[n-1][amount];
    }
};