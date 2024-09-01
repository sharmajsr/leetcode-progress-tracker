class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int curIndex,int p,int q,vector<vector<int>> &vis){
        if(curIndex == word.size()) return true;
       
        vis[p][q] = 1;
        int rows[] = { 0 , 0 , 1 , -1 } ;
        int cols[] = { 1 ,-1 , 0 , 0 };
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<4;i++){
            int nRow = rows[i] + p ;
            int nCol = cols[i] + q;
            // if ( p==1 && q==1){
            //     cout<<nRow<<" "<<nCol<<endl;
            // }
            
            // if( nRow >= 0 && nRow < n &&
            //     nCol >=0 && nCol < m && p ==1 && q==1)
            // cout<<nRow<<" "<<nCol<<" "<< board[nRow][nCol] <<" "<< word[curIndex]<<" "<<vis[nRow][nCol]<<endl;
            if( nRow >= 0 && nRow < n &&
                nCol >=0 && nCol < m &&
                vis[nRow][nCol] == 0 && 
                board[nRow][nCol] == word[curIndex] && solve(board,word,curIndex+1, nRow,nCol,vis)
            ){
                // cout<<p <<" "<<q<<" " <<nRow<<" "<<nCol<<" "<<curIndex+1<<" "<<vis[nRow][nCol]<<endl;
                return true;
            }
        }
        vis[p][q] = 0;
        // cout<<endl;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>vis1(n,vector<int>(m,0));
        int curIndex =0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // memset(vis,0,sizeof(vis));
                
                vis=vis1;
                // cout<<i<<" "<<j<<endl;
                if(board[i][j] == word[0] && solve(board,word,1,i,j,vis)){
                    
                    return true;
                }
            }
        }
        return false;
    }
};
//caa
//aaa
//bcd