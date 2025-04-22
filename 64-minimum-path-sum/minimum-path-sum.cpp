class Solution {
public:
    int solve(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if( m ==0 and n== 0){
            return grid[m][n];
        }
        if(m<0 or n<0)  return INT_MAX;
        if(dp[m][n] !=-1)return dp[m][n];
        int left = INT_MAX;
        int up = INT_MAX;
        left = solve(m,n-1,grid,dp);
        up = solve(m-1,n,grid,dp);
        return dp[m][n] = min(left,up)+grid[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};