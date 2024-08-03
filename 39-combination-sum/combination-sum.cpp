class Solution {
public:
    void solve(vector<int>nums , vector<int>op, int target , map<vector<int>,int>&mp){
        if( target  == 0){
            sort(op.begin(),op.end());
            mp[op]=1;
            // se.insert(op);
            return;
        }
        for(auto i :nums){
            if(  target-i >= 0){
                op.push_back(i);
                solve(nums,op,target-i,mp);
                op.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>op;
        set<vector<int>>se;
        map<vector<int>,int> mp;
        solve(candidates,op,target,mp);
        for(auto i : mp){
            ans.push_back(i.first);
        }
        return ans;
    }
};