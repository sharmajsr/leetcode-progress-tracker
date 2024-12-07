class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tsum = 0 ;
        for(auto i : nums)  tsum += i;
        if( tsum & 1 )  return false;
        // cout<<"passed even check\n";
        tsum/=2;
        vector<vector<int>>dp(n+1,vector<int>(tsum+1,0));
        // int dp[n+1][tsum+1]={0};
        for(int i = 0 ; i <= n; i++) dp[i][0] = 1;

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ;j <=tsum ; j++){
                if( j < nums[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                // cout<<dp[i][j]<< " "; 
            }
            // cout<<endl;
        }

        return dp[n][tsum];
    }
};