class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() , sumSoFar = 0 , maxSum = INT_MIN;
        for(auto i : nums){
            sumSoFar += i ;
            if(maxSum < sumSoFar)   maxSum = sumSoFar;
            if(sumSoFar < 0 ) sumSoFar =0;
        }
        return maxSum;
    }
};