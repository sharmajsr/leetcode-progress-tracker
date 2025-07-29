class Solution {
public:
    vector<vector<int>>dp;
    int lcs(string &s1, string &s2, int idx1, int idx2){
        if(idx1 <0 or idx2 < 0){
            return 0;
        }
        if(dp[idx1][idx2] != -1)    return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2]){
            return 1+ lcs(s1,s2,idx1-1,idx2-1);
        }
        return dp[idx1][idx2] = max(lcs(s1,s2,idx1-1,idx2), lcs(s1,s2,idx1,idx2-1 ));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size() , n2 = s2.size();
        dp.resize(n,vector<int>(n2,-1));
        return lcs(s1,s2,s1.size()-1,s2.size()-1);
    }
};