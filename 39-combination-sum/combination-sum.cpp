class Solution {
public:
    void solve(vector<int>op,set<vector<int>>&ans,vector<int>cand,int target,int curSum,int start){
        if(curSum == target){
            sort(op.begin(),op.end());
            ans.insert(op);
            return;
        }
        for(int i = start ; i < cand.size() ; i++){
            if(target >= (curSum + cand[i]) ){
                // solve(op,ans,cand,target,curSum  ,start+1);
                // cout<<start<<" "<<i<<" "<<curSum<<" " <<cand[i]<<endl;
                op.push_back(cand[i]);
                solve(op,ans,cand,target,curSum +cand[i] ,start);
                op.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>op;
        set<vector<int>>ans;
        vector<vector<int>>ans1;
        solve(op,ans,candidates,target,0,0);
        for(auto i :ans){
            ans1.push_back(i);
        }
        return ans1;
    }
};