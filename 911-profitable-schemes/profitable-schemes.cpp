class Solution {
public:
    int MOD = 1e9+7;
    int solve(int n, int minProfit, vector<int>& group, vector<int>& profit,int idx,vector<vector<vector<int>>>&dp){
        
        if (idx < 0) {
            return (minProfit <= 0) ? 1 : 0;
        }
        
        if(dp[n][minProfit][idx] != -1 )   return dp[n][minProfit][idx];
        // cout<<n<<" "<<idx<<endl;
        
        int not_pick = solve(n,minProfit,group,profit,idx-1,dp)%MOD;
        int pick = 0 ;
        if (n >= group[idx]) {
            int remainingProfit = max(0, minProfit - profit[idx]); // Profit can’t go negative
            pick = solve(n - group[idx], remainingProfit , group, profit, idx - 1,dp) % MOD;
        }

        return dp[n][minProfit][idx] = (pick + not_pick)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(minProfit+1,vector<int>(profit.size(),-1)));
        solve(n,minProfit,group,profit,profit.size()-1,dp);
        return dp[n][minProfit][profit.size()-1]%MOD;
    }
};