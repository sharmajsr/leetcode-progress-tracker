class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount ;i++){
            for(int j=0;j<coins.size();j++){
               if( i>= coins[j] ){
                    // cout<<i<<" "<<coins[j]<<" "<<dp[i-coins[j]]<<endl;
                    int maxi = dp[i-coins[j]] == INT_MAX?dp[i-coins[j]]:1+dp[i-coins[j]];
                    dp[i] = min(dp[i] , maxi);
               }
            }
        }
        return dp[amount] == INT_MAX ? -1 :dp[amount];
    }
};