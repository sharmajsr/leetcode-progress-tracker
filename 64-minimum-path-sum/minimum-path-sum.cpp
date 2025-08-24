class Solution {
public:
    int solve(vector<vector<int>>& grid ,int r , int c,vector<vector<int>>&dp){
        if(r == 0 and c == 0 ){
            return grid[r][c];
        }
        if(r < 0 or c < 0 ){
            return INT_MAX;
        }
        if(dp[r][c] != -1)    return dp[r][c];
        int t1 = solve(grid, r-1,c,dp);
        int t2 = solve(grid, r, c-1,dp);

        return dp[r][c] =  grid[r][c] + min(t1,t2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,n-1,m-1,dp);
    }
};