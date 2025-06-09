class Solution {
public:
    void solve(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&vis,int &temp){
        int rows[] = { 0,0 ,1, -1} , cols[] = {1,-1,0,0} ;
        vis[x][y]=1;
        ++temp;
        for(int i =0;i < 4;i++){
            int nr = rows[i] + x;
            int nc = cols[i] + y;
            if(nr >=0 and nc>=0 and nr < grid.size() and nc < grid[0].size() and grid[nr][nc] == 1 and vis[nr][nc] == 0){
                solve(nr,nc,grid,vis,temp);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0 ; i < n ;i++){
            for(int j= 0 ; j <m ; j++){
                if(grid[i][j] == 1 and vis[i][j] == 0 ){
                    int temp = 0 ;
                    solve(i,j,grid,vis,temp);
                    maxArea = max(maxArea,temp);
                }
            }
        }
        return maxArea;
    }
};