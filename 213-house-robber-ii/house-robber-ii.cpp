class Solution {
public:
    int solve(vector<int>&nums){
        int n = nums.size();
        vector<int>dp(nums.size(),-1);
        dp[0] = nums[0];
        for(int i=1 ;i < n ; i++){
            int pick = nums[i] ;
            if(i>1) pick += dp[i-2];
            int not_pick = dp[i-1];
            dp[i] = max(pick,not_pick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        vector<int>nums2,nums1;
        for(int i=0;i<nums.size()-1;i++){
            nums1.push_back(nums[i]);
            nums2.push_back(nums[i+1]);
        }
        return max(solve(nums1),solve(nums2));
        // nums.erase(nums.begin()+nums.size()-1);
    }
};