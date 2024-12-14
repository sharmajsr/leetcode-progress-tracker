class Solution {
public:
    // void rotAdjacentOranges(vector<vector<int>>& grid,int p,int q,int &numberOfMinutes){
    //     queue<int>q;
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        int numberOfMinutes = 0 ,cz= 0 ,co = 0;
        queue<pair<int,int>>q;
        int rows[] = {0,0,1,-1};
        int cols[]= {1,-1,0,0};
        for(int i=0; i <grid.size(); i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2 ){
                    q.push({i,j});
                }
                else if(grid[i][j] == 0 ){
                    ++cz;
                }
                else if(grid[i][j] == 1){
                    ++co;
                }
            }
        }
        if(q.empty() and co > 0 )   return -1;
        else if(q.empty() ) return 0;
        
        while(!q.empty()){
            queue<pair<int,int>>qu;
            while(!q.empty()){
                auto top = q.front();
                q.pop();
                // cout<<top.first<<" "<<top.second<<" "<<numberOfMinutes<<endl;
                for(int i=0;i<4;i++){
                    int nRow = rows[i] + top.first;
                    int nCol = cols[i] + top.second;
                    if(nRow >= 0 and nRow < grid.size() 
                    and nCol >=0 and nCol <grid[0].size() && 
                    grid[nRow][nCol] == 1 
                    ){
                        grid[nRow][nCol] = 2;
                        qu.push({nRow,nCol});
                    }

                }

            }
            ++numberOfMinutes;
            q=qu;
        }
         for(int i=0; i <grid.size(); i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    // ++numberOfMinutes;
                   return -1;
                }
            }
        }
        return numberOfMinutes-1;
    }
};