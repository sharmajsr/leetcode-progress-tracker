class Solution {
public:
    int solve(vector<vector<int>>& grid,queue<pair<pair<int,int>,int>>q ,vector<vector<int>>&vis,int &cnt){
        int rows[] = {0,0,1,-1}  , cols[] = {1,-1,0,0} ;
        // int cnt = 0 ; 
        
        while(!q.empty()){
            auto top = q.front();q.pop();
            pair<int,int> cor = top.first;
            int time = top.second ; 
            
            for(int i= 0; i < 4; i++ ){
                int nr = cor.first + rows[i];
                int nc = cor.second + cols[i];

                if(nr >=0 and nr < grid.size() and nc >=0 and nc < grid[0].size() and grid[nr][nc] == 1  ){
                    // vis[nr][nc] =1; 
                    cnt = max(cnt,time+1);
                    grid[nr][nc]=0;
                    q.push({{nr,nc},time+1});
                }
            }
        }
        return cnt;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size() , m = grid[0].size() ,cnt = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i =0 ;i < n; i++){
            for(int j= 0 ;j < m;j++){
                if(grid[i][j]==2){
                    vis[i][j]  = 1;
                    q.push({{i,j},0});
                }
            }
        }
        cnt = solve(grid,q,vis,cnt);

        for(int i =0 ;i < n; i++){
            for(int j= 0 ;j < m;j++){
                if(grid[i][j] == 1){
                    cout<<"fresh : "<<i<<" "<<j<<endl;
                    return -1;
                }
            }
        }

        return cnt;
    }
};