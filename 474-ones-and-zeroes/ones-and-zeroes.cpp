class Solution {
public:
    int solve(vector<string>& strs,int m,int n,int idx,vector<int>&v,vector<vector<vector<int>>>&dp){

        if(idx >= strs.size())   return 0;

        if(dp[m][n][idx] != -1)  return dp[m][n][idx];

        int take = 0 ;
        if( m >= v[idx] and n >= (strs[idx].size()-v[idx]) )
        take = 1 + solve(strs,m-v[idx],n-(strs[idx].size()-v[idx]),idx+1,v,dp);
        // cout<<m<<" "<<n<<" "<<idx<<" "<<take<<endl;
        int not_take  = solve(strs,m,n,idx+1,v,dp);
        // cout<<m<<" "<<n<<" "<<idx<<" "<<not_take<<endl;
        return dp[m][n][idx] = max(take,not_take);
    }
    int cntZeros(string s){
        int zeros = 0; 
        for(auto i : s) if( i == '0') ++zeros;
        return zeros;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int p = strs.size();
        vector<vector<vector<int>>>dp(101,vector<vector<int>>(101,vector<int>(601,-1)));
        vector<int>v;
        for(auto i : strs){
            int zer = cntZeros(i);
            v.push_back(zer);
        }
        solve(strs,m,n,0,v,dp);
        return dp[m][n][0];
    }
};