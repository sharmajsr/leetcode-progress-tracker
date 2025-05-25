class Solution {
public:
    void solve(int pos,int neg,string cur,vector<string>&ans,int &n){
        if(cur.size() == 2 * n ){
            ans.push_back(cur);
            return;
        }
        if(pos > 0){
            solve(pos-1,neg+1,cur+'(',ans,n);
        }
        if(neg>0){
            solve(pos,neg-1,cur+')',ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,0,"",ans,n);
        return ans;
    }
};