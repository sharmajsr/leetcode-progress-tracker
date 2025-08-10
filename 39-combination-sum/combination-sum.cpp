class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>path, int target,vector<int>& c, int idx ){
        if(target == 0 ){
            ans.push_back(path);
            return;
        }
        for(int i=idx; i<c.size(); i++){
            if(target >= c[i]){
                path.push_back(c[i]);
                solve(ans,path,target-c[i],c,i);
                path.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> ans;
        solve(ans,{},target,c,0);
        return ans;
    }
};