class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int tsum = 0 , n =stones.size() ,ans =INT_MAX,total ;
        for(auto i : stones)    tsum += i;
        total = tsum;
        tsum/=2;
        // int dp[n+1][tsum+1];
        vector<vector<int>>dp(n+1,vector<int>(tsum+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=tsum;j++){
                if(j>=stones[i-1]){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]]; 
                }else{
                    dp[i][j] =dp[i-1][j];
                }
            }
        }
        for(int i=0;i<=tsum;i++){
            if(dp[n][i] > 0 ){
                ans = total -2*i;
            }
        }
        return ans;
    }
};