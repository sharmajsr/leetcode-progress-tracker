class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n= nums.size();
        int mask = 0 , maxSoFar = 1 , i= 0 , j =0 ;
        // for(int i=0;i<n;i++){
        //     mask = nums[i] ;
        //     for(int j= i+1  ; j <n ;j++){
        //         int p = mask & nums[j];
        //         if( p == 0){
        //             maxSoFar = max(maxSoFar,j-i+1);
        //             mask = mask | nums[j];
        //         }else{
        //             break;
        //         }
        //     }
        // }
        while(j<n){
            int p = mask & nums[j];
            if( p == 0 ){
                mask = mask | nums[j];
                maxSoFar = max(maxSoFar,j-i+1);
                ++j;
            }else{
                mask ^= nums[i];
                ++i;
            }
        }
        return maxSoFar;
    }
};
// [1,3,8,48,10]
// i =0 , j = 0 , mask = 1
// i =0 , j = 1 , mask = 0
// i = 1, j = 1 , mask = 3
// i = 1, j = 2 , mask = 11
// i = 1, j = 3 , mask = 56
// i = 8, j = 4 , mask = 52
// 