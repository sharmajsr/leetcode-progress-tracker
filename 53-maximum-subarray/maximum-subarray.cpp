class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum_ending_here = 0 ;
        for(auto i : nums){
            sum_ending_here += i ;
            if(sum_ending_here > maxSum )   maxSum = sum_ending_here;
            if(sum_ending_here < 0 ) sum_ending_here =0;
        }
        return maxSum;
    }
};

//i1
// 5,4,-1,7,8 
// 23

// 5,4,-20,7,8 
// 9 ,-11 ,15