class Solution {
public:
    int countAliveNeighbours(vector<vector<int>> board, int k, int j){
        
        int rows[] = { 0 , 0 , 1, -1 ,-1 , -1 ,1,  1 };
        int cols[] = { 1, -1, 0 , 0 ,-1 , 1 ,-1 ,1 };
        int nearestAliveCell = 0;
        for(int i=0;i<8;i++){
            int nRow = k + rows[i];
            int nCol = j + cols[i];
            if(
            nRow >= 0 and nRow < board.size() and
            nCol >= 0 and nCol < board[0].size() and
               board[nRow][nCol]==1 
            ){
                ++nearestAliveCell;
            }

        }
        // cout<<k<<" "<<j<<" "<<board[k][j]<<" "<<nearestAliveCell<<endl;
        return nearestAliveCell;
    }
    // 11 - > 2,0
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>b1 = board;
        int n = board.size();
        int m= board[0].size();
        for( int i=0;i<n ; i++){
            for( int j=0;j<m;j++){
                int cnt = countAliveNeighbours(b1,i,j);
                // cout<<cnt<<endl;
                if(cnt < 2 ) board[i][j] = 0 ;
                // else if(cnt == 2 || cnt == 3) continue;
                else if(cnt > 3)    board[i][j] = 0 ;
                else if(b1[i][j] == 0 and cnt == 3 ) board[i][j] = 1 ;
                // cout<<i<<" "<<j<<" "<<b1[i][j]<<" "<<board[i][j]<<" "<<cnt<<endl;
            }
        }
    }
};