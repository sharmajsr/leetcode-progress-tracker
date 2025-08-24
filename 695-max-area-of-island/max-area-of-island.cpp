class Solution {
public:
    void solve(vector<vector<int>>& grid, int r , int c ,int &cur){
        int rows[] = { 0,0,1,-1};
        int cols[] = {1,-1,0,0};
        for(int i=0;i<4; i++){
            int nr = r+ rows[i];
            int nc = c + cols[i];
            if(nr >=0 and nr  < grid.size() and nc >=0 and nc < grid[0].size() and grid[nr][nc] == 1){
                grid[nr][nc] = 0 ;
                cur +=1 ;
                solve(grid,nr,nc,cur);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n ; i++){
            for(int j=0; j<m ;j++){
                if(grid[i][j] == 1){
                    int cur = 1 ;
                    grid[i][j]=0;
                    solve(grid, i , j, cur );
                    // cout<<i<<" "<<j<<" "<<cur<<endl;
                    ans = max(ans,cur);
                }
            }
        }
        return ans;
    }
};