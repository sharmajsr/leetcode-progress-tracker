class Solution {
public:
    void solve(int n,int parent,string op,vector<string>&ans ){
        if(n == 0 ){
            ans.push_back(op);
            return ;
        }
        string ar[] = {"a","b","c"};
        for(int i=0;i<3;i++){
            if( i != parent)
            solve(n-1,i,op + ar[i] , ans);
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        solve(n,-1,"",ans);
        return k>ans.size() ? "" : ans[k-1];
    }
};