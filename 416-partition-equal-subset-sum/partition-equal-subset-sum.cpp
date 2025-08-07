class Solution {
public:
    bool solve(vector<int>&arr,int sum, int idx,vector<vector<int>>&dp){
        if(sum == 0){
            return true;
        }
        if(idx == 0){
            return arr[idx] == sum;
        }
        if(dp[idx][sum] != -1)  return dp[idx][sum];
        bool not_take = solve(arr,sum,idx-1,dp);
        bool take = false;
        if(sum >= arr[idx]){
            take = solve(arr,sum-arr[idx],idx-1,dp);
        }
        
        return dp[idx][sum]=  take or not_take;
    }
    bool canPartition(vector<int>& nums) {
        int tsum = 0;
        int n = nums.size();
        for(auto i : nums)  tsum += i;
        if(tsum & 1) return false;
        int hsum = tsum/2;
        vector<vector<int>>dp(n+1,vector<int>(hsum+1,-1));
        return solve(nums,hsum,n-1,dp);
    }
};