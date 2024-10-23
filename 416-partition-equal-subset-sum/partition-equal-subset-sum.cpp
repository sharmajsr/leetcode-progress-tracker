class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tsum = 0,n =nums.size(); 
        for(auto i: nums)   tsum+= i;
        int halfSum = tsum/2;
        if(tsum % 2 !=0 )   return false;
        int dp[n+1][halfSum+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=halfSum;j++){
                if( i == 0 )        dp[i][j] = 0 ;
                if( j== 0)          dp[i][j] = 1 ;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=halfSum;j++){
                if(j >= nums[i-1]){
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][halfSum];
    }
};