class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int rows[] = {0,0,1,-1};
        int cols[] = {1,-1,0,0};
        int n = grid.size(), m = grid[0].size(),ans = 0,zc = 0;
        // if(n == 1 and m == 1 and grid[0][0] == 0  ) return 0;
        // if(n == 1 and m == 1 and grid[0][0] == 2  ) return 0;
        // if(n == 0 and m== 0 and grid[0][0] = 0 or grid[0][0] ==1 ) return -1;
        for(int i=0; i<n ;i++){
            for(int j= 0; j< m;j++ ){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 0 ){
                    ++zc;
                }
            }
        }
        if(n*m ==zc) return 0;
        while(!q.empty()){
            // auto top = q.front();
            queue<pair<int,int>>qu;
            ++ans;
            while(!q.empty()){
                auto top = q.front();
                q.pop();
                int p1 = top.first;
                int q1 = top.second;
                for(int i=0;i<4;i++){
                    int nrow = rows[i] + p1;
                    int ncol = cols[i] + q1; 
                    if( nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol] == 1 ){
                        grid[nrow][ncol] = 2;
                        qu.push({nrow,ncol});
                    }
                }
            }
            q=qu;
        }
        cout<<"n and m"<<n<<" "<<m<<endl;
         for(int i=0; i<n ;i++){
            for(int j= 0; j< m;j++ ){
                cout<<grid[i][j]<<" ";
                if(grid[i][j] == 1){
                    return -1;
                }
            }cout<<endl;
        }
        return ans-1;
    }
};