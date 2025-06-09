class Solution {
public:
    void solve(vector<vector<int>>& grid,int x,int y,vector<vector<int>>& vis,int &perimeter){
        int rows[]={0,0,1,-1};
        int cols[]={1,-1,0,0};
        vis[x][y]=1;
        for(int i= 0 ; i<4 ;i++){
            int nr = rows[i] + x;
            int nc = cols[i] + y;
            if(nr>=0 and nc>=0 and nr < grid.size() and nc < grid[0].size() and grid[nr][nc] ==1){
                if( vis[nr][nc] == 0 )
                solve(grid,nr,nc,vis,perimeter);
            }else{
                ++perimeter;
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0; i <n ;i++){
            for(int j= 0 ; j<m; j++){
                if(grid[i][j] == 1 and vis[i][j] == 0 ){
                    solve(grid,i,j,vis,perimeter);
                }
            }
        }
        return perimeter;
    }
};