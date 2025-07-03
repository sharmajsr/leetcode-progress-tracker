class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis(n,1);
        int maxA =1 ; 
        for(int i= 1; i <n; i++){
            for(int j= 0; j < i; j++ ){
                if(nums[j]< nums[i] ){
                    lis[i]= max(lis[i], 1 + lis[j]);
                }
                maxA = max(maxA,lis[i]);
            }
        }
        return maxA;
        
    }
};