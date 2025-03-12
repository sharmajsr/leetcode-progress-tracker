class Solution {
public:
    void solve(vector<vector<int>>&ans ,vector<int>op,vector<int>nums){
        if(nums.size() == 0 ){
            ans.push_back(op);
            return;
        }
        vector<int>op1 = op;
        vector<int>op2 = op;
        op1.push_back(nums[nums.size()-1]);
        // nums.pop_back();
        nums.erase(nums.end());
        solve(ans,op1,nums);
        solve(ans,op2,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans,{},nums);
        return ans;

    }
};