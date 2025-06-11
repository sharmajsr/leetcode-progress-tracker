class Solution {
public:
    int getLCS(string s1, string s2,int x ,int y,vector<vector<int>>&dp){
        if(x == 0 || y == 0 )   return 0;
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        if(s1[x-1] == s2[y-1])  return dp[x][y] = 1+ getLCS(s1,s2,x-1,y-1,dp);
        else
        return dp[x][y] = max(getLCS(s1,s2,x-1,y,dp),getLCS(s1,s2,x,y-1,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return getLCS(s1,s2,s1.size(),s2.size(),dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};