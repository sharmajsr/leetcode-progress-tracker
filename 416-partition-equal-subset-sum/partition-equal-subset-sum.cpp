class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tsum = 0 ,n =nums.size() ; 
        for(auto i : nums){
            tsum += i ;
        }
        if(tsum & 1)    return false;
        tsum /=2;
        int dp[n+1][tsum+1];
        
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            dp[i][0] =1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=tsum ;j++){
                if( j >= nums[i-1]){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][tsum];
    }
};