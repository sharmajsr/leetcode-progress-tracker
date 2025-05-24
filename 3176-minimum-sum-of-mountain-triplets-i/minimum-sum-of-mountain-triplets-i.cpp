class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int minSum = INT_MAX, n= nums.size();
        for(int i= 0 ; i<n; i++){
            for(int j= i+1 ;j <n;j++){
                for(int k = j+1 ; k <n; k++){
                    if(nums[i] < nums[j] and nums[j] > nums[k]){
                        minSum = min(minSum,nums[i]+nums[j]+nums[k]);
                    }
                }
            }
        }
        return minSum == INT_MAX  ? -1 : minSum;
    }
};