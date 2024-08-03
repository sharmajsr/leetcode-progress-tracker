class Solution {
public:
    void solve(vector<int>nums, set<vector<int>>&se, vector<int>op){
        if(nums.size() == 0 ) {
            sort(op.begin(),op.end());
            se.insert(op);
            return;
        }
        vector<int>op1 = op;
        vector<int>op2 =op;
        op2.push_back(nums[nums.size()-1]);
        nums.pop_back();
        // cout<<nums.size()<<" " <<op1.size()<<" "<<op2.size()<<endl;
        solve(nums,se,op1);
        solve(nums,se,op2);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>se;
        vector<int>op;
        solve(nums,se,op);
        for(auto i : se){
            ans.push_back(i);
        }
        return ans;
    }
};