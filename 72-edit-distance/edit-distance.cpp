class Solution {
public:
vector<vector<int>>dp;
    int solve(string s1, string s2, int x1, int x2){
        if( x1 < 0 or x2 < 0 ){
            return max(x1,x2);
        }
        if(dp[x1][x2] != -1)    return dp[x1][x2];
        if(s1[x1] == s2[x2]){
            return   solve(s1,s2,x1-1,x2-1);
        }
        return dp[x1][x2] = 1 + min(solve(s1,s2,x1,x2-1), min(solve(s1,s2,x1-1,x2),solve(s1,s2,x1-1,x2-1)));
        
    }
    int minDistance(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        dp.resize(n1,vector<int>(n2,-1));
        return 1+solve(s1,s2,n1-1,n2-1);
    }
};