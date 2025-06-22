class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size() ,cnt = 0;
        vector<vector<int>>temp(n,vector<int>(m,0));
        for(int i= 0; i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++){
                sum += matrix[i][j];
                temp[i][j] = sum;
            }
        }


        for(int startCol= 0 ;startCol < m ;startCol++){
            for(int j= startCol ; j < m ; j++){
                    unordered_map<int,int>um;
                    um.insert({0,1});
                    int sum = 0;

                    for(int row = 0; row <n ; row++){
                        
                        sum += temp[row][j] - (startCol > 0  ? temp[row][startCol-1] : 0 ) ;
                        int diff  = sum - k;
                        if(um.find(diff) != um.end()){
                            cnt += um[diff];
                        }
                        ++um[sum];
                        
                    }
            }
        }
        
        return cnt;



    }
};