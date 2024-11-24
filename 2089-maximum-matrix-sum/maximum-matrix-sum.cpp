class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long negCnt = 0;
        long long n = matrix.size();
        long long totalPositiveSum = 0 ;
        long long smallestNumber = INT_MAX;
        for(long long i=0;i<n;i++){
            for(long long j=0;j<n;j++){
                totalPositiveSum += abs(matrix[i][j]);
                if( abs(matrix[i][j]) < smallestNumber )
                smallestNumber = abs(matrix[i][j]);
                if(matrix[i][j] < 0)    ++negCnt;
            }
        }
        negCnt %=2;
        // cout<<negCnt<<" "<<totalPositiveSum<<" "<<smallestNumber<<endl;
        if(negCnt)  totalPositiveSum-=(2*smallestNumber);
        return totalPositiveSum;
        
    }
};