class Solution {
public:
    void solve(int pos,int neg,vector<string>&ans,string op,int n ){
        if(op.size() == n*2){
            ans.push_back(op);
            return;
        }
        if(pos>0)   solve(pos-1,neg+1,ans,op+"(",n);
        if(neg>0)   solve(pos,neg-1,ans,op+")",n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,0,ans,"",n);
        return ans;
    }
};