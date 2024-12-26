class Solution {
public:

    int countSubsetSum(vector<int>nums,int target){
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if( j>= nums[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum = 0 , countOfZeros = 0 ;
        vector<int>nums1;
        for(auto i : nums){
            tsum += i ;
            if(i != 0 )   nums1.push_back(i);
            else {
                ++countOfZeros;
            }
        } 
        if(tsum + target < 0 )  return 0;
        if((tsum + target) %2 ==1  )    return 0;

        
        int fsum = (abs(tsum)+abs(target))*0.5;
        int ans = countSubsetSum(nums1,fsum);
        cout<<ans<<endl;
        return countOfZeros > 0 ? ans * pow(2,countOfZeros) : ans;
    }
};