class Solution {
public:
    void solve(vector<vector<char>>& grid,vector<vector<int>>& vis,int r, int c){
        vis[r][c] =1;
        int rows[] = {0,0,1,-1};
        int cols[]= {1,-1,0,0};
        for(int i=0;i<4;i++){
            int nr = rows[i]+r;
            int nc = cols[i]+c;
            if(nr >=0 and nr< grid.size() and nc>=0 and nc<grid[0].size() and grid[nr][nc] == '1' and vis[nr][nc] == 0){
                solve(grid,vis,nr,nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        int cnt = 0; 
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i= 0; i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' and vis[i][j] == 0 ){
                    ++cnt;
                    solve(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};