class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid , int cr, int cc,vector<vector<int>>&dp){
        int n = obstacleGrid.size() , m = obstacleGrid[0].size();
        if(cr == obstacleGrid.size()-1 and cc == obstacleGrid[0].size()-1){
            return 1;
        }
        if(cr > obstacleGrid.size()-1 or cc > obstacleGrid[0].size()-1){
            return 0;
        }
        if(dp[cr][cc] != -1 ) return dp[cr][cc];
        int p1 =0 , p2 = 0;
        if( cr+1 < n  and  obstacleGrid[cr+1][cc] == 0 ){
            p1 = solve(obstacleGrid, cr+1,cc,dp);
        }
        if(cc+1 < m and obstacleGrid[cr][cc+1] == 0 ){
            p2 = solve(obstacleGrid, cr,cc+1,dp);
        }
        return dp[cr][cc] = p1 + p2 ;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size() , m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] ) return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(obstacleGrid,0,0,dp);
    }
};