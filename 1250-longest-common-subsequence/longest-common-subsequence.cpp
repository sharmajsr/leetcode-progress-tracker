class Solution {
public:
    // ;
    int lcs(string &s1, string &s2, int i, int j,vector<vector<int>>&dp){
        // cout<<i<<" "<<j<<endl;

        if(i == 0 or j == 0 ) return dp[i][j] = 0;

        if(dp[i][j] != -1) return dp[i][j] ;

        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 1 + lcs(s1,s2, i-1,j-1,dp);
        }

        return dp[i][j] = max(lcs(s1,s2,i-1,j,dp) , lcs(s1,s2,i,j-1,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size() , n2 = s2.size();
        vector<vector<int>>dp;
        dp.resize(n+1,vector<int>(n2+1,-1));
        return lcs(s1,s2,n,n2,dp);
    }
};