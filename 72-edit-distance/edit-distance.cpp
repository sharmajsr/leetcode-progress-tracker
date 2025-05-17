class Solution {
public:
int solve(string w1,string w2,int idx1, int idx2,vector<vector<int>>&dp){
    if(idx1 <= 0 or idx2 <=0 )   return max(idx1,idx2);
    if(dp[idx1][idx2] != -1)    return dp[idx1][idx2];
    if(w1[idx1-1] == w2[idx2-1]){
        return dp[idx1][idx2] = solve(w1,w2,idx1-1,idx2-1,dp);
    }else {
        return dp[idx1][idx2] = 1+ min(solve(w1,w2,idx1-1,idx2,dp),min(solve(w1,w2,idx1-1,idx2-1,dp),solve(w1,w2,idx1,idx2-1,dp)));
    }
}
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,word1.size(),word2.size(),dp);
    }
};