class Solution {
public:
    int lcs(string text1,string text2,int m,int n,vector<vector<int>>&dp){
        if( m <= 0 or n <= 0)    return 0;
        if(dp[m-1][n-1] != -1)  return dp[m-1][n-1];
        if(text1[m-1] == text2[n-1]){
            return dp[m-1][n-1] = 1+ lcs(text1,text2,m-1,n-1,dp);
        }
        return dp[m-1][n-1] = max(lcs(text1,text2,m-1,n,dp),lcs(text1,text2,m,n-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        if( m== 0 or n ==0 )    return 0;
        vector<vector<int>>dp(m+2,vector<int>(n+2,0));
        for(int i = 1 ; i<= m; i++){
            for(int j =1 ;j <= n;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        // return lcs(text1,text2,m,n,dp);
        return dp[m][n];
    }
};