class Solution {
public:
    void solve(vector<int>nums , vector<int>op,int curSum, int target , map<vector<int>,int>&mp){
        if( target  == curSum){
            sort(op.begin(),op.end());
            mp[op]=1;
            // se.insert(op);
            return;
        }
        for(auto i :nums){
            if( i + curSum <= target){
                op.push_back(i);
                solve(nums,op,curSum+i,target,mp);
                op.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>op;
        set<vector<int>>se;
        map<vector<int>,int> mp;
        solve(candidates,op,0,target,mp);
        for(auto i : mp){
            ans.push_back(i.first);
        }
        return ans;
    }
};