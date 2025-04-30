class Solution {
public:
void solve(int target,int idx,vector<int>&candidates,set<vector<int>> &ans,vector<int>cur){
    if(target == 0 ){
        ans.insert(cur);
        return;
    }
    if(idx > candidates.size() ){
        return;
    }
    for(int i= idx ; i<candidates.size() ; i++){
        if( i > idx and candidates[i] == candidates[i-1] ) continue;
        
        if(target >= candidates[i]){
            cur.push_back(candidates[i]);
            solve(target-candidates[i],i+1,candidates,ans,cur);
            cur.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>ans;
        vector<vector<int>>ans1;
        sort(candidates.begin(),candidates.end());
        solve(target,0,candidates,ans,{});
        for(auto i : ans){
            ans1.push_back(i);
        }
        return ans1;
    }
};