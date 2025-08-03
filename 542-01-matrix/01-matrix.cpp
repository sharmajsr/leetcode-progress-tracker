class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ,cnt =0 ;
        int rows[] = {0,0,1,-1}, cols[]={1,-1,0,0};
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            queue<pair<int,int>>qu;
            
            while(!q.empty()){
                auto fr = q.front();
                q.pop();
                ans[fr.first][fr.second]=cnt;
                for(int i= 0;i<4; i++){
                    int nr = fr.first + rows[i];
                    int nc = fr.second + cols[i];
                    if(nr>=0 and nr < grid.size() and 
                    nc>=0 and nc< grid[0].size() and 
                    ans[nr][nc] > 1+ans[fr.first][fr.second]){
                        ans[nr][nc] = 1+ans[fr.first][fr.second];
                        qu.push({nr,nc});
                        
                    }
                }
                
            }
            q = qu;
            ++cnt;
        }
        return ans;
    }
};