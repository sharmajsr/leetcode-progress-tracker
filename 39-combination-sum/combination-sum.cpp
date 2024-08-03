class Solution {
public:
    void solve(vector<int>nums , vector<int>op,int curSum, int target,set<vector<int>>&se){
        if( target  == curSum){
            sort(op.begin(),op.end());
            se.insert(op);
            return;
        }
        for(auto i :nums){
            if( i + curSum <= target){
                op.push_back(i);
                solve(nums,op,curSum+i,target,se);
                op.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>op;
        set<vector<int>>se;
        solve(candidates,op,0,target,se);
        for(auto i :se){
            ans.push_back(i);
        }
        return ans;
    }
};