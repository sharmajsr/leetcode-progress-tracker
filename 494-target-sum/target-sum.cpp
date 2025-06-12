class Solution {
public:
    int solve(vector<int>&nums,int target,int idx,vector<vector<int>>&dp){
        if(target == 0) return 1;
        if(idx == 0){
            if(target == nums[idx] )    return dp[idx][target] = 1;
            else return dp[idx][target] = 0;
        }

        if(dp[idx][target] != -1)   return dp[idx][target] ;
        int pick = 0 , not_pick = 0;
        if(target >= nums[idx]) pick = solve(nums,target-nums[idx],idx-1,dp);
        not_pick = solve(nums,target,idx-1,dp);
        return dp[idx][target] = pick+not_pick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum = 0 , czero = 0 ;
        target = abs(target);
        for(int i= 0 ; i < nums.size() ; i++)    tsum += nums[i];
        cout<<tsum<<" "<<target<<endl;
        if((tsum + target )%2 == 1 )    return 0;
        vector<int>nums1;
        for(auto i : nums){
            if(i != 0)  nums1.push_back(i);
            else        czero++;
        }
        if(czero == nums.size()){
            return target == 0 ? pow(2,czero) : 0 ;
        }
        cout<<"printing nums1 \n";
        for(auto i : nums1) cout<<i<<" ";
        cout<<endl;
        int val = (tsum+target)/2;
        int n1 = nums1.size();
        vector<vector<int>>dp(n1+1,vector<int>(val+1,-1));
        
        solve(nums1,val,n1-1,dp);
        // for(int i =0 ;i <n1 ;i++){
        //     for(int j= 0; j<=val ;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        return dp[n1-1][val]*pow(2,czero);
    }
};