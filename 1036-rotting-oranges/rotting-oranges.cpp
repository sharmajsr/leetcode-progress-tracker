class Solution {
public:
    void solve(vector<vector<int>>& grid,queue<pair<pair<int,int>,int>>q,int &maxi){
        int rows[] = {0,0,1,-1};
        int cols[] = {1,-1,0,0};
        while(!q.empty()){
            auto fr = q.front();
            pair<int,int>coord =  fr.first;
            int time = fr.second;
            
            q.pop();
            for(int i= 0 ;i < 4 ;i++){
                int r = rows[i] + coord.first;
                int c = cols[i] + coord.second;
                if(r >= 0 and r <grid.size() and c >= 0 and c < grid[0].size() and grid[r][c] == 1 ){
                    grid[r][c] = 2;
                    maxi = max(maxi,time+1);
                    q.push({{r,c},time+1});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size() ,maxi = 0 ;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i= 0; i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2 and vis[i][j] == 0 ){
                    q.push({{i,j},0});
                }
            }
        }
        solve(grid,q,maxi);
        for(int i= 0; i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 ){
                    return -1;
                }
            }
        }


        return maxi;
    }
};