class Solution {
public:
    void solve(vector<vector<int>>&grid, queue<pair<int,pair<int,int>>>q, int &fresh, int &time ){
        int rows[] = { 0,0,1,-1};
        int cols[] = {1,-1,0,0};
        while(!q.empty()){
            auto top = q.front();q.pop();
            int curTime = top.first;
            int dx = top.second.first;
            int dy = top.second.second;
            for(int i=0;i<4;i++){
                int nr = dx + rows[i];
                int nc = dy + cols[i];
                if(nr >=0 and nr<grid.size() and nc>=0 and nc<grid[0].size() and grid[nr][nc] == 1){
                    grid[nr][nc] =2;
                    q.push({curTime+1, {nr,nc}});
                    --fresh;
                    time = curTime+1;
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n = grid.size() , m =grid[0].size() , fresh = 0, time = 0;
        for(int i=0; i<n ;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                
                }else if(grid[i][j] == 1){
                    ++fresh;
                }
            }
        }

        solve(grid,q,fresh, time);
        if(fresh > 0 ){
            return -1;
        }
        return time;
    }
};