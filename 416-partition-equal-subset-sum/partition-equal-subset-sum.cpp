class Solution {
public:
    bool isSubsetSum(vector<int>&nums,int idx,int hsum,vector<vector<int>>&dp){
        if( hsum == 0 or idx == 0){
            dp[idx][hsum] = 0 ;
            
            if(hsum == 0)   return dp[idx][hsum] = true;
            if(idx == 0 and hsum == nums[idx])  return dp[idx][hsum] =  true;
            return false;
        }
        if( dp[idx][hsum] != -1 ) return dp[idx][hsum];
        bool not_pick = isSubsetSum(nums,idx-1,hsum,dp);
        bool pick = false;
        if( hsum >= nums[idx] )  pick = isSubsetSum(nums,idx-1,hsum-nums[idx],dp);
        dp[idx][hsum] = 1 ;
        return dp[idx][hsum] = pick or not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int tsum = 0 , n= nums.size();
        for(auto i : nums){
            tsum += i;
        }
        if(tsum % 2 )    return false;
        tsum /=2 ;
        // int hsum = tsum;
        vector<vector<int>>dp(n+1,vector<int>(tsum+1,-1));
        vector<vector<bool>>dp1(n+1,vector<bool>(tsum+1,false));
        // cout<<tsum << " "<<nums.size()-1<<endl;
        isSubsetSum(nums,nums.size()-1,tsum,dp);
        // for(int idx = 0 ; idx< nums.size(); idx++){
        //     for(int hsum = tsum ; hsum >=0 ;hsum--){
        //         if( hsum == 0 or idx == 0){
        //             if(hsum == 0)   dp[idx][0] = true;
        //             if(idx == 0 and hsum == nums[idx])  dp[idx][hsum] = true;
        //             dp[idx][hsum] = false;
        //             continue;
        //         }
        //         bool not_pick = dp[idx-1][hsum];
        //         bool pick = false;
        //         if( hsum >= nums[idx] )  pick = dp[idx-1][hsum-nums[idx]];
        //         dp[idx][nums] = pick or not_pick;
        //     }
        // }
        return dp[n-1][tsum];

    }
};