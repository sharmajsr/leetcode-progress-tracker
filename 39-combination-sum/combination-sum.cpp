class Solution {
public:
    void solve(vector<int>op,int target,vector<int>& candidates,vector<vector<int>>&ans,int idx){
        if(candidates.size() == idx){
            if(target == 0 )    ans.push_back(op);
            return;
        }
        
        solve(op,target,candidates,ans,idx+1);
        // if()
        if(target >= candidates[idx]){
            op.push_back(candidates[idx]);
            solve(op,target-candidates[idx],candidates,ans,idx);
            op.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>op;
        vector<vector<int>>ans;
        solve(op,target,candidates,ans,0);
        return ans;
    }
};