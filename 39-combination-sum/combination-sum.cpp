class Solution {
public:
    void solve(int target,vector<int>candidates,int start,vector<int>op,vector<vector<int>>&ans){
        if(target == 0 ){
            ans.push_back(op);
            return;
        }
        for(int i= start;i<candidates.size();i++){
            if(target >= candidates[i]){
                op.push_back(candidates[i]);
                solve(target - candidates[i] , candidates , i,op,ans);
                op.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        
        solve(target, candidates, 0,{},ans);
        return ans;
    }
};