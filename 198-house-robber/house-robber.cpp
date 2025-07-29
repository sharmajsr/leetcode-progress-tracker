class Solution {
public:
vector<int>dp;
    int solve(vector<int>nums, int idx){
        if(idx<0)   return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = nums[idx] + solve(nums,idx-2);
        int not_take = solve(nums,idx-1);
        return dp[idx] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        dp.resize(n,-1);
        solve(nums,n-1);
        return dp[n-1];
    }
};