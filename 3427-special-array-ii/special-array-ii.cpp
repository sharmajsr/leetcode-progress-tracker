class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n =nums.size();
        vector<bool>ans;
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            if(nums[i-1]%2 != nums[i]%2){
                dp[i]=dp[i-1]+1;
            }
        }
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<dp[i]<<endl;
        }
        for(auto i :queries){
            int start = i[0];
            int end =i[1];
            if(dp[end]-dp[start]+1 == (end-start+1)){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
// 3  4  1  2 6  7 8 9
// -1 1 -1  1 1 -1 1 -1
// -1 0 -1  0 1  0 1  0