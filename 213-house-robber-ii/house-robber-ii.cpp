class Solution {
public:
    int solve(vector<int>&nums,int idx,vector<int>&dp){
        if(idx < 0 )        return 0;
        if(idx == 0 )       return dp[0] = nums[0];
        if(dp[idx]!= -1)    return dp[idx];
        return dp[idx] = max(solve(nums,idx-1,dp),nums[idx] + solve(nums,idx-2,dp)); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 1) return nums[0];
        vector<int>n1,n2;
        vector<int>dp1(n,-1),dp2(n,-1);
        for(int i=0;i<n-1;i++){
            n1.push_back(nums[i]);
            n2.push_back(nums[i+1]);
        }
        return max(solve(n1,n-2,dp1),solve(n2,n-2,dp2));
    }
};