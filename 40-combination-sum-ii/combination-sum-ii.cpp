class Solution {
public:
    void solve(vector<int>op,int target,vector<int>& candidates,vector<vector<int>>&ans,int idx){
         
        if(target == 0){
            ans.push_back(op);
            return;
        }

        for(int i = idx ; i < candidates.size() ; i++){
            if( i > idx and candidates[i] == candidates[i-1] ) continue;

            if( candidates[i] > target ) break;

            op.push_back(candidates[i]);
            solve(op,target-candidates[i],candidates,ans,i+1);
            op.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans1;

        vector<int>op;
        
        solve(op,target,candidates,ans1,0);

        return ans1;
    }
};