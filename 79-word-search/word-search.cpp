class Solution {
public:
    vector<vector<int>>vis;
    bool solve(int p ,int q ,vector<vector<char>>& board , string &word,int idx){
        vis[p][q]=1;
        int rows[] = { 0,0,1,-1};
        if(idx == word.size()){
            return true;
        }
        int cols[] = { 1,-1,0,0};
        for(int i= 0 ;i <4 ;i++){
            int nr = rows[i] + p;
            int nc = cols[i] + q;
            if(nr >=0 and nr < board.size() and
                nc >=0 and nc <board[0].size() and board[nr][nc] == word[idx] and vis[nr][nc] == 0 and solve(nr,nc,board,word,idx+1)){
                    return true;
                }
        }
        vis[p][q]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m =board[0].size(); 
        // vector<vector<int>>vis(n,vector<int>(m,0));
        vis.resize(n,vector<int>(m,0));
        for(int i = 0; i <n;i++){
            for(int j= 0; j<m;j++){
                if(board[i][j] == word[0] and solve(i,j,board,word,1)){
                    vis[i][j]=1;
                    return true;
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
};