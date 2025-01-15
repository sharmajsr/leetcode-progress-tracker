class Solution {
public:
    void solve(vector<int>nums,vector<int>temp,vector<vector<int>>&ans){
        if(nums.size() == 0 ){
            ans.push_back(temp);
            return;
        }
        vector<int>op1 = temp;
        vector<int>op2 = temp ;
        op1.push_back(nums[0]);
        nums.erase(nums.begin());
        solve(nums,op1,ans);
        solve(nums,op2,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,temp,ans);
        return ans;
    }
};