class Solution {
public:
    int solve(string s,string t,int idx1,int idx2,vector<vector<int>>&dp){
        if(idx1 == 0 or idx2 == 0)    return 0;
        if(dp[idx1][idx2]!= -1) return dp[idx1][idx2];

        if(s[idx1-1] == t[idx2-1]){
            return 1+ solve(s,t,idx1-1,idx2-1,dp);
        }else{
            return max(solve(s,t,idx1-1,idx2,dp),solve(s,t,idx1,idx2-1,dp));
        }

    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        int n = s.size();
        reverse(t.begin(),t.end());
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(s,t,n,n,dp);
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int idx1 = 1 ; idx1<= n ;idx1++ ){
            for(int idx2 = 1 ; idx2 <=n;idx2++){
                if(s[idx1-1] == t[idx2-1]){
                    dp[idx1][idx2] = 1+ dp[idx1-1][idx2-1];
                }else{
                    dp[idx1][idx2] =  max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
                }
            }
        }
        return dp[n][n];

    }
};