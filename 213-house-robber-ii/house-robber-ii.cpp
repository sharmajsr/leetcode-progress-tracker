class Solution {
public:
    int solve(int idx,vector<int>&nums,vector<int>&dp){
        if(idx < 0 )    return 0;
        if(dp[idx] != -1)   return dp[idx];
        int pick = nums[idx] + solve(idx-2,nums,dp);
        int not_pick = solve(idx-1,nums,dp);
        return dp[idx] = max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( nums.size() == 1)   return nums[0];
        vector<int>n1 ,n2 ; 
        vector<int>dp(n,-1) , dp1(n,-1);
        for(int i = 0 ; i< nums.size()-1;i++){
            n1.push_back(nums[i]);
            n2.push_back(nums[i+1]);
        }
        return max( solve(n1.size()-1,n1,dp) , solve(n2.size()-1,n2,dp1) ) ;
    }
};