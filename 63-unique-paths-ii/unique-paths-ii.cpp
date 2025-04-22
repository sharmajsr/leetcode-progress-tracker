class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(m == 0 and n== 0){
            if(obstacleGrid[m][n] == 1) return 0;
            return 1;
        }
        else if(m < 0 or n < 0){
            return 0;
        }
        else if(obstacleGrid[m][n] == 1){
            return 0;
        }
        if(dp[m][n] != -1)  return dp[m][n];
        return dp[m][n] = solve(m-1,n,obstacleGrid,dp) +solve(m,n-1,obstacleGrid,dp);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,obstacleGrid,dp);
    }
};