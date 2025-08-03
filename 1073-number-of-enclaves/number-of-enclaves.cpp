class Solution {
public:
    void dfs(int x ,int y, vector<vector<int>>&grid){
        grid[x][y]=2;
        int rows[]={0,0,1,-1} ,cols[] ={1,-1,0,0} ;
        for(int i= 0; i<4;i++){
            int nr = x + rows[i];
            int nc = y + cols[i];
            if(nr>=0 and nc >=0 and nr< grid.size() and nc < grid[0].size() and grid[nr][nc] == 1){
                dfs(nr,nc,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , ans= 0 ;
        for(int i= 0; i<n;i++){
            if(grid[i][0]==1)
            dfs(i,0,grid);
            if(grid[i][m-1]==1)
            dfs(i,m-1,grid);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1)
            dfs(0,j,grid);
            if(grid[n-1][j]==1)
            dfs(n-1,j,grid);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    ++ans;
                }
            }
        }
        return ans;
    }
};