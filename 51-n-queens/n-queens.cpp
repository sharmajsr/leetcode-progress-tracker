class Solution {
public:
vector<vector<string>>ans; 
    bool isPathSage(int p,int q,int n){
        return p>=0 and q>=0 and p<n and q<n;
    }
    bool issafe(vector<vector<string>>board,int p,int q,int n){
        for(int i=0;i<n;i++){
            // cout<<n<<" "<<i<<" "<<p<<" "<<q<<endl;
            
            if( i!=q and board[p][i] == "Q"){
                return false;
            }
            if( i!=p and board[i][q] == "Q"){
                return false;
            }
        }
        // Check up-left diagonal
        for (int r = p - 1, c = q - 1; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == "Q") return false;
        }

        // Check up-right diagonal
        for (int r = p - 1, c = q + 1; r >= 0 && c < n; r--, c++) {
            if (board[r][c] == "Q") return false;
        }

        // Check down-left diagonal
        for (int r = p + 1, c = q - 1; r < n && c >= 0; r++, c--) {
            if (board[r][c] == "Q") return false;
        }

        // Check down-right diagonal
        for (int r = p + 1, c = q + 1; r < n && c < n; r++, c++) {
            if (board[r][c] == "Q") return false;
        }

        return true;
    }
    vector<string> convertAns(vector<vector<string>>board){
        vector<string>temp;
        for(auto i : board){
            string t1;
            for(auto j : i ){
                if( j==".") t1 +=".";
                else    t1+="Q";
            }
        temp.push_back(t1);
        }
        return temp;
    }
    void solve(int n, vector<vector<string>>board ,int row){
        // cout<<row<<" "<<n<<endl;
        if(row == n ){
            ans.push_back(convertAns(board));
            return;
        }
        // cout<<row<<" "<<n<<endl;
        for(int i=0;i<n;i++){
            board[row][i]="Q";
            // cout<<row<<" "<<n<<" "<<i<<" "<<board[row][i]<<endl;
            if(issafe(board,row,i,n)){
                
                solve(n,board,row+1);
            } 
              
            board[row][i]=".";
            // cout<<row<<" "<<n<<" "<<i<<" "<<board[row][i]<<endl;
        }


    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<vector<string>>board(n,vector<string>(n,"."));
        // vector<vector<string>>board;
        solve(n,board,0);
        return ans;

    }
};