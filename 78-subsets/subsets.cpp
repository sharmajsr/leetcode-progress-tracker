class Solution {
public:
    void solve(vector<int> inp,vector<vector<int>>&ans, vector<int>op){
        // cout<<inp.size()<<endl;
        if(inp.size() == 0 ){
            ans.push_back(op);
            return;
        }
        
        vector<int>op1 = op;
        vector<int>op2 = op;
        op2.push_back(inp[inp.size()-1]);
        // inp.erase(inp.begin() + inp.size()-1);
        inp.pop_back();
        solve(inp,ans,op1);
        solve(inp,ans,op2);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        solve(nums,ans,op);
        return ans;
    }
};