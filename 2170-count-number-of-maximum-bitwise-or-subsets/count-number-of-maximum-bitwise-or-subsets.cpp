class Solution {
public:
    int findSubset(int curVal, int curIndex,int targetVal,vector<int>nums,int &cnt,vector<vector<int>>&dp){
        
        
        if(curIndex == nums.size()){
            return curVal == targetVal ? 1 : 0;
        }

        if(dp[curIndex][curVal] != -1) {
            return dp[curIndex][curVal];
        }

        return dp[curIndex][curVal] = findSubset( curVal ,curIndex+1,targetVal,nums,cnt,dp) +
                findSubset( curVal | nums[curIndex] ,curIndex+1,targetVal,nums,cnt,dp);

    }
    int countMaxOrSubsets(vector<int>& nums) {
        
        int n = nums.size(),cnt = 0;
        int maxBitwise = 0 ;
        for(auto i : nums) maxBitwise |= i;
        vector<vector<int>>dp(n+1,vector<int>(maxBitwise+1,-1));
        int ans = findSubset(0,0,maxBitwise,nums,cnt,dp);
        return ans;
    }
};
//  2 - 3
//  2,2 - 3
//  2,2,2 - 1
