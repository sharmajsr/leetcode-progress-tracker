class Solution {
public:
    bool solve(int p , int q ,vector<vector<char>>& board,string &word,vector<vector<int>>&vis,int idx){
        if(idx == word.size())  return true;
        // cout<<p<<" "<<q<<" "<<idx<<endl;
        vis[p][q] = 1 ;
        int rows[] = { 0 , 0 ,1 ,-1};
        int cols[] = {1, -1 , 0 ,0 };
        for(int i=0;i<4;i++){
            int nrow = rows[i] + p;
            int ncol = cols[i] + q;
            if(nrow >=0 and nrow < board.size() and ncol >=0 and ncol < board[0].size() and board[nrow][ncol] == word[idx] and vis[nrow][ncol] == 0 and solve(nrow,ncol,board,word,vis,idx+1)){
                return true;
            }
        }
        vis[p][q] = 0 ;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>vis1(n,vector<int>(m,0));
        for(int i= 0 ; i <n; i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] and solve(i,j,board,word,vis,1)){
                    return true;
                }else{
                    vis = vis1;
                }
            }
        }
        return false;
    }
};