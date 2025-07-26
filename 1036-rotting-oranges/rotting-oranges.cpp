class Solution {
public:
    int solve(queue<pair<int,int>>q,vector<vector<int>>&grid){
        int rows[]={0,0,1,-1};
        int cols[]={1,-1,0,0};
        int time = 0 , cnt= 0 ;
        while(!q.empty()){
            queue<pair<int,int>>qu;
            ++time;
            while(!q.empty()){
                auto fr = q.front();
                q.pop();
                int r = fr.first;
                int c = fr.second;
                for(int i= 0;i<4;i++){
                    int nr = r + rows[i];
                    int nc = c + cols[i];
                    if(nr >=0 and nc>=0 and nr < grid.size() and nc < grid[0].size()  and grid[nr][nc] == 1){
                        grid[nr][nc] =2;
                        qu.push({nr,nc});
                    }
                }
            }
            q=qu;
        }
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), cnt = 0 ;
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int time = 0; 
        for(int i= 0 ; i <n ;i++){
            for(int j=0;j<m ;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    ++cnt;
                }
            }
        }
        if(q.size() == 0 ){
            if(cnt == 0 )   return 0;
            else return -1;
        }  
        time = solve(q,grid);
        for(int i= 0 ; i <n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return time-1;
    }
};