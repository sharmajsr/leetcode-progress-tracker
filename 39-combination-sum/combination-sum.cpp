class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&candidates,int idx,int target,vector<int>cur){
        if(target == 0 ){
            ans.push_back(cur);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(target >= candidates[i]){
                cur.push_back(candidates[i]);
                solve(ans,candidates,i,target-candidates[i],cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        solve(ans,candidates,0,target,{});
        return ans;
    }
};