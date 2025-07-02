class Solution {
public:
    bool solve(vector<int>&nums, int idx,int target,vector<vector<int>>&dp){
        if(idx == 0 ){
            return target == nums[0];
        }
        if(dp[idx][target] != -1)   return dp[idx][target];
        bool take = false;
        if(target >= nums[idx])
        take = solve(nums,idx-1,target-nums[idx],dp);
        bool not_take = solve(nums,idx-1,target,dp);
        // cout<<idx<<" "<<take<<" "<<not_take<<endl;
        return dp[idx][target] = take or not_take;
    }
    bool canPartition(vector<int>& nums) {
        int tsum = 0;
        for(auto i : nums)  tsum += i;
        if(tsum & 1)    return false;

        int n = nums.size();

        vector<vector<int>>dp(n,vector<int>(tsum/2+1,-1));
        // tsum/=2;
        cout<<tsum/2<<endl;
        return solve(nums,n-1,tsum/2,dp);
    }
};