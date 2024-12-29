class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ,ans = 0;
        for(int i=1;i<n;i++){
            for(int j= 0; j< m;j++){
                if( i== 0 and j== 0 )  continue;
                int t1 = INT_MAX;
                if( i != 0 ){
                    t1 = grid[i-1][j];
                }else{
                    t1 =0;
                }
                int mini = t1;
                // cout<<i<<" "<<j<<" "<<grid[i][j]<<" "<<(mini>=grid[i][j]) ? mini-grid[i][j]+1: " "<<endl;
                if(grid[i][j] > mini )  continue;
                else{
                    int diff = (mini - grid[i][j] +1) ;
                    ans += diff;
                    cout<<i<<" "<<j<<" "<<mini<<" "<<grid[i][j]<<" "<<diff<<" ";
                    grid[i][j] += diff; 
                    cout<<grid[i][j]<<endl;
                    
                }

            }
        }
        return ans;
    }
};