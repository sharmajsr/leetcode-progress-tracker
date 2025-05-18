class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size() == 1)  return stones[0];
        int tsum = 0 , n = stones.size();
        for(auto i : stones)    tsum += i;
        int hsum = tsum/2;
        int ans = INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(hsum+1,0));
        for(int i= 0 ; i < n; i++){
            dp[i][0]=1;
        }

        for(int i= 1 ; i <= n; i++){
            for(int j= 1; j<=hsum ;j++){
                if(j>=stones[i-1]){
                    dp[i][j] =dp[i-1][j-stones[i-1]] or dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }

           
        for(int j= 0; j<=hsum ;j++){
            // cout<<dp[n][j]<<" "; 
            if(dp[n][j] == 1 ){
                int temp = tsum - j * 2;
                ans= min(ans,tsum-2*j);
            }
        }

        return ans;

    }
};