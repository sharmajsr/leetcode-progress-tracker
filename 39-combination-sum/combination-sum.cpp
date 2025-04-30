class Solution {
public:
    void solve(vector<int>cur, int target, set<vector<int>>&ans,vector<int>& candidates,int idx){
        if( target == 0 ){
            ans.insert(cur);
            return;
        }
        if(idx >= candidates.size() ){
            return;
        }
        solve(cur,target,ans,candidates,idx+1);
        // cout<<idx<<" "<<target<<endl;
        if(target >= candidates[idx] ){
            cur.push_back(candidates[idx]);
            solve(cur,target-candidates[idx],ans,candidates,idx);
            solve(cur,target-candidates[idx],ans,candidates,idx+1);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<vector<int>>ans1;
        solve({},target,ans,candidates,0);
        for(auto i : ans){
            ans1.push_back(i);
        }
        return ans1;
    }
};