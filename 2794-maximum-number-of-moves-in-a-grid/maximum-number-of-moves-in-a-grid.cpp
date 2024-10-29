class Solution {
public:
vector<vector<int>>dp;
    int solve(int r,int c, vector<vector<int>>& grid){
        if(dp[r][c] != -1)  return dp[r][c];
        int rows[] = {-1 , 0 , 1 };
        int cols[] = {1  , 1 , 1 };
        int ans = 0;
        
        for(int i=0;i<3;i++){
            int nrow = rows[i] + r;
            int ncol = cols[i] + c;
            if(
                nrow >= 0 and nrow < grid.size() and 
                ncol >= 0 and ncol < grid[0].size() and 
                grid[nrow][ncol] > grid[r][c]
            ){
                ans = max(ans, solve(nrow,ncol,grid) );  
            }
            
        }
        return  dp[r][c] = ans+1;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(),ans = 0;
        dp.resize(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){
            dp[i][0] = max(dp[i][0],solve(i,0,grid));
            ans = max(ans,dp[i][0]);
        }

        return ans-1;
        
    }
};

// 00 01 02 03
// 10 11 12 13
// 20 21 22 23
// 30 31 32 33