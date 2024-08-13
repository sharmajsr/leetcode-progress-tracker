class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tsum = 0 ; 
        for(auto i : nums ) tsum += i;
        if(tsum%2) return false;
        tsum = tsum/2;
        int n = nums.size();
        int t[n+1][tsum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=tsum;j++){
                if( i == 0 ) t[i][j] = 0 ;
                if( j== 0 ) t[i][j] =1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=tsum;j++){
                if( j>= nums[i-1]){
                    t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]];
                }else{
                    t[i][j] = t[i-1][j] ;
                }
            }
        }
        return t[n][tsum];
    }
};