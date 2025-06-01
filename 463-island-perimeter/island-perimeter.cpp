class Solution {
public:
    void dfs(vector<vector<int>>& grid,int r, int c,vector<vector<int>>&vis,int &ans){
        vis[r][c]=1;
        int rows[]={0,0,1,-1};
        int cols[]={1,-1,0,0};
        for(int i= 0 ;i <4 ;i++){
            int nr = r + rows[i];
            int nc = c + cols[i];
            if(nr>=0 and nc>=0 and nr < grid.size() and nc< grid[0].size() and grid[nr][nc] == 1 ){
                if(vis[nr][nc] == 0){
                    dfs(grid,nr,nc,vis,ans);
                }
            } 
            else    ans++;
            
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans = 0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 and grid[i][j] == 1)
                dfs(grid,i,j,vis,ans);
            }
        }
        return ans;
    }
};