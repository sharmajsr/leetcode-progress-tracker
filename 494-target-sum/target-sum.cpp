class Solution {
public:
    vector<int>v;
    int countOfSubsetSum(int n,int target,vector<int>nums){
        // int dp[n+1][target+1];
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<=n;i++){
                dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(j >= nums[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][target];
    }
    // int solve(int n,int target,int curr,vector<int>nums){
        
    //     if( n == 0 ){
    //         if( target == curr )  return 1;
    //         else return 0;
    //     }
    //     if(v[n] != -1)  return v[n];
    //     return v[n] = solve(n-1,target,curr+nums[n-1],nums) + solve(n-1,target,curr-nums[n-1],nums);
        
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     // v.resize(nums.size()+1,-1);
    //     // return solve(nums.size(),target,0,nums);
    //     int countOfZeros = 0,tsum = 0 ;
    //     for(auto i : nums){ 
    //         if( i == 0 ) ++countOfZeros ; 
    //         tsum += i ;
    //     }
    //     if((tsum + target) %2 ==1  )    return 0;
    //     int ans = countOfSubsetSum(nums.size(),target,nums);
    //     cout<<ans<<endl;
    //     return ans*pow(2,countOfZeros); 
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        // If the target is out of range of possible sums
        if (abs(target) > totalSum) return 0;
        
        // If totalSum + target is odd, no solution exists
        if ((totalSum + target) % 2 != 0) return 0;
        
        // Calculate the subset sum we need to find
        int subsetSum = (totalSum + target) / 2;
        
        // DP to count number of subsets with given sum
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;
        
        for (int num : nums) {
            for (int j = subsetSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[subsetSum];
    }
};