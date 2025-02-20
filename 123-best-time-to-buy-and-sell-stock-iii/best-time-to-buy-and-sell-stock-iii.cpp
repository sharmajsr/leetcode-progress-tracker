class Solution {
public:
    int solve(vector<int>& prices, int idx, int buy, int cap,
              vector<vector<vector<int>>>& dp) {
        if (cap == 0 or idx == prices.size())
            return 0;
        int profit = 0;
        if (dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];
        if (buy) {
            profit = max(-prices[idx] + solve(prices, idx + 1, 0, cap, dp),
                         solve(prices, idx + 1, 1, cap, dp));
        } else {
            profit = max(prices[idx] + solve(prices, idx + 1, 1, cap - 1, dp),
                         solve(prices, idx + 1, 0, cap, dp));
        }
        return dp[idx][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // solve(prices,0,1,2,dp);
        // return dp[0][1][2];
        // vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> dp(2, vector<int>(3, 0));
        vector<vector<int>> temp(2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--) {    // prices
            for (int j = 0; j < 2; j++) {     // buy or sell
                for (int k = 1; k < 3; k++) { // capacity
                    // if( i == n or k == 0 ){
                    //     dp[i][j][k] =0;
                    //     continue;
                    // }
                    if (j == 1) {
                        temp[j][k] = max(-prices[i] + dp[0][k], dp[1][k]);
                    } else {
                        temp[j][k] = max(prices[i] + dp[1][k - 1], dp[0][k]);
                    }
                }
            }
            dp=temp;
        }
        return dp[1][2];
    }
};