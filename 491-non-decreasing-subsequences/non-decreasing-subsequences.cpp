class Solution {
public:
    void solve(vector<int>nums,vector<int>op,set<vector<int>>&ans){
        if(nums.size() == 0 ){
            if(op.size() > 1)
            ans.insert(op);
            return ;
        }
        vector<int>op1,op2;
        op1 = op2 = op;
        int firstElement = nums[0];
        nums.erase(nums.begin());
        solve(nums,op1,ans);
        if(op2.size() > 0 and op2[op2.size()-1] <= firstElement){
            op2.push_back(firstElement);
            solve(nums,op2,ans);
        }else if(op2.size() == 0){
            op2.push_back(firstElement);
            solve(nums,op2,ans);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>se;
        vector<vector<int>>ans;
        vector<int>op;
        solve(nums,op,se);
        for(auto i :se){
            ans.push_back(i);
        }
        return ans;
    }
};