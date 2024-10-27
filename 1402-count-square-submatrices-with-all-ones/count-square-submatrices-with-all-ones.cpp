class Solution {
public:
    bool checkSquareExists(vector<vector<int>>& matrix,int p,int q,int squareSize){
        int rowEnd = p + squareSize ,colEnd = q + squareSize;
        if(rowEnd>matrix.size() or colEnd >matrix[0].size())  return false;
        for(int i=p ; i<rowEnd ; i++){
            for(int j=q ; j<colEnd ; j++){
                if(!matrix[i][j])   return false;
            }
        }
        return true;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n  = matrix.size(),ans = 0 ;
        int m = matrix[0].size();
        int maxSquareSize = min(n,m);
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int l=1; l <= maxSquareSize; l++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j] and checkSquareExists(matrix,i,j,l)){
                        // cout<<l<<" "<<i<<" "<<j<<" "<<ans<<endl;
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

