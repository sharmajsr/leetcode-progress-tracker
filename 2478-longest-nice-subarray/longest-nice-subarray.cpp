class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n= nums.size();
        int mask = 0 , maxSoFar = 1 , i = 0 , j = 0;
        for(int i=0;i<n;i++){
            mask = nums[i] ;
            for(int j= i+1  ; j <n ;j++){
                int p = mask & nums[j];
                cout<<i<<" "<<j<<" "<<nums[j]<<" "<<p<<endl;
                if( p == 0){
                    maxSoFar = max(maxSoFar,j-i+1);
                    mask = mask | nums[j];
                }else{
                    break;
                }
            }
        }
        return maxSoFar;
    }
};