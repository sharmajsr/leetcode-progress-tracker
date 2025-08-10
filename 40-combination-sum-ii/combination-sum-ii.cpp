class Solution {
public:
    void solve(set<vector<int>>&ans, vector<int>path, int target,vector<int>& c, int idx ){
        if(target == 0 ){
            ans.insert(path);
            return;
        }
        for(int i=idx; i<c.size(); i++){
            if( i > idx and c[i] == c[i-1] ) continue;
        
            if(target >= c[i]){
                path.push_back(c[i]);
                solve(ans,path,target-c[i],c,i+1);
                path.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        set<vector<int>>se;
        vector<vector<int>> ans;
        solve(se,{},target,c,0);
        for(auto i: se){
            ans.push_back(i);
        }
        return ans;
    }
};