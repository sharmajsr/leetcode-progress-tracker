class Solution {
private:
    void bfs(vector<vector<int>>& grid,int &ans,vector<vector<int>>& vis,int &cnt,queue<pair<pair<int,int>,int>>q){
        // queue<pair<pair<int,int>,int>>q;
        // vis[r][c] = 2;
        // q.push({{r,c},0});
        int rows[]={0,0,1,-1};
        int cols[]={1,-1,0,0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr = rows[i] + it.first.first;
                int nc = cols[i] + it.first.second;
                int nq = it.second;
                if(nr>=0 and nc>=0 and nr<grid.size() and nc<grid[0].size() and grid[nr][nc] == 1 ){
                    q.push({{nr,nc},nq+1});
                    ans = max(ans,nq+1);
                    grid[nr][nc]=0;
                }
                
            }
        }

    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int ans = 0 ,cntFresh = 0 ,cnt = 0 ;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i= 0;i<n;i++){
            for(int j= 0; j<m;j++){
                if(grid[i][j] == 2 ){
                    q.push({{i,j},0});
                }
            }
        }
        bfs(grid,ans,vis,cnt,q);
        for(int i= 0;i<n;i++){
            for(int j= 0; j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};

// 2 2 2
// 2 2 1
// 0 2 2