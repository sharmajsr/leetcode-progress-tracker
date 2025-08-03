class Solution {
public:
    void dfs(int x, int y,vector<vector<char>>&board){
        // cout<<x<<" "<<y<<endl;
        board[x][y] = '1';
        int rows[]= {0,0,1,-1};
        int cols[]= {1,-1,0,0};
        for(int i= 0; i<4;i++){
            int nr = x + rows[i];
            int nc = y + cols[i];
            if(nr >=0 and nc >=0 and nr< board.size() and nc < board[0].size() and board[nr][nc]== 'O'){
                // board[nr][nc] = '1';
                dfs(nr,nc,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();
        for(int i= 0; i<n;i++){
            if(board[i][0] == 'O')
            dfs(i,0,board);
            if(board[i][m-1] == 'O')
            dfs(i,m-1,board);
        }
        for(int j=0;j<m;j++){
            if(board[0][j] == 'O')
            dfs(0,j,board);
            if(board[n-1][j] == 'O')
            dfs(n-1,j,board);
        }
        for(int i= 0; i < n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(board[i][j] == '1'){
                    board[i][j]= 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j]= 'X';
                }
            }
        }

    }
};