class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size() ==1 )  return stones[0];
        int n = stones.size(),tsum = 0 ,ans = INT_MAX;
        for(auto i : stones)    tsum +=i;
        int hsum = tsum/2;
        vector<vector<int>>dp(n+1,vector<int>(hsum+1,0));
        // int dp[n+1][hsum+1];
        for(int i=0;i<=n;i++)   dp[i][0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=hsum;j++){
                if(j>= stones[i-1]){
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-stones[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        cout<<tsum<<endl;
        for(int i=1;i<=hsum;i++){
            // cout<<dp[n][i]<<" ";
            if(dp[n][i] == 1 ){
                // cout<<i<<" ";
                int s1 = i;
                int s2 = tsum - s1;

                int diff = s1 > s2 ? s1-s2 : s2-s1;
                ans = min( ans , diff );
            }
        }
        return ans;
    }
};