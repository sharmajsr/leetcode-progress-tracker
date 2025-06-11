class Solution {
public:
    int solve(string s1, string s2,int x,int y,vector<vector<int>>&dp){
        if(x  == 0 or y == 0 ) return dp[x][y] = max(x,y) ;
        if(dp[x][y] != -1)  return dp[x][y];
        if(s1[x-1] == s2[y-1]){
            return dp[x][y] = solve(s1,s2,x-1,y-1,dp);
        }else{
            return dp[x][y] = 1 + min(solve(s1,s2,x-1,y-1,dp),min(solve(s1,s2,x,y-1,dp),solve(s1,s2,x-1,y,dp)));
        }
    }
    int minDistance(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // solve(s1,s2,n,m,dp);
        // return dp[n][m] == -1 ? 0 : dp[n][m];
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>cur(m+1,0) , prev(m+1,0);

        // for(int i= 0; i <= n ; i++) dp[i][0] = i; 
        for(int j= 0; j <= m ; j++) prev[j] = j; 


        for(int i= 1 ; i <= n; i++){
            for(int j=0;j<=m;j++){
                if(j==0){
                    cur[0]=i;
                    continue;
                }
                if(s1[i-1] == s2[j-1]){
                    cur[j] =prev[j-1];
                }else{
                    cur[j] = 1+ min(cur[j-1],min(prev[j],prev[j-1]));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};

// insert  -> horses , ros -> x, y-1
// delete  -> horse , ros -> x-1 ,y
// replace -> horss , ros -> x-1, y-1