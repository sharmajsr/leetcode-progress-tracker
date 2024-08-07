class Solution {
public:
    int solve(vector<int>nums , int n , vector<int>&dp){
        if( n == 0 )    return dp[n] = nums[0];
        if (n<0)    return 0;

        if (dp[n] != -1)    return dp[n];
        int curr = nums[n] + solve(nums,n-2,dp);
        int prev =solve(nums,n-1,dp);

        return dp[n] = max(curr,prev);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return  nums[0];
        vector<int>nums1 ,nums2;

        int n = nums.size();

        for(int i=0;i<n-1;i++){
            nums1.push_back(nums[i]);
            nums2.push_back(nums[i+1]);
        }
        vector<int>dp(n-1,-1);
        vector<int>dp1(n-1,-1);

        solve(nums1,n-2,dp);
        solve(nums2,n-2,dp1);
        return max(dp[n-2],dp1[n-2]);
    }
};