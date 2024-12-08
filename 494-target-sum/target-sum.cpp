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
    int findTargetSumWays(vector<int>& nums, int target) {
        // v.resize(nums.size()+1,-1);
        // return solve(nums.size(),target,0,nums);
        int countOfZeros = 0,tsum = 0 ;
        vector<int>nums1;
        for(auto i : nums){ 
            if( i == 0 ) ++countOfZeros ; 
            else{
                nums1.push_back(i);
            }
            tsum += i ;
        }
        if(countOfZeros > 0 ) nums = nums1;
        if(tsum + target < 0 )  return 0;
        if((tsum + target) %2 ==1  )    return 0;
        int newTarget = (tsum + target)/2;
        int ans = countOfSubsetSum(nums.size(),newTarget,nums);
        cout<<"countOfZeros : "<<countOfZeros<<endl;
        return countOfZeros > 0 ? ans*pow(2,countOfZeros) :ans; 
    }
};