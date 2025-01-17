class Solution {
public:
vector<vector<int>>vis;
    void dfs(int p ,int q ,vector<vector<char>>& grid){
        int rows[] = {0,0,1,-1};
        int cols[] = {1,-1,0,0};
        grid[p][q]='0';
        vis[p][q] = 1 ;
        for(int i=0;i<4;i++){
            int nrow = rows[i] + p;
            int ncol = cols[i] + q;
            if(nrow>=0 and ncol >=0 and nrow<grid.size() and ncol < grid[0].size() and grid[nrow][ncol] == '1' and vis[nrow][ncol]==0){
                dfs(nrow,ncol,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vis.resize(grid.size(),vector<int>(grid[0].size(),0)) ;int  ans =0 ;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,grid);
                    ++ans;
                }
            }
        }
        return ans;
    }
};