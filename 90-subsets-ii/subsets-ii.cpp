class Solution {
public:
    void solve(vector<int>nums,vector<int>cur,set<vector<int>> &ans){
        if(nums.size() == 0 ){
            ans.insert(cur);
            return;
        }
        vector<int>op1 = cur,op2 =cur;
        op1.push_back(nums[0]);
        nums.erase(nums.begin());
        solve(nums,op1,ans);
        solve(nums,op2,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<vector<int>>ans1;
        solve(nums,{},ans);
        for(auto i :ans){
            ans1.push_back(i);
        }
        return ans1;

    }
};