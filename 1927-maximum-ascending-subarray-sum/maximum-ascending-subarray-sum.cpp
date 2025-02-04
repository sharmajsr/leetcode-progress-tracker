class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int curMax = 0 ; 
        int lMax = 0 ;
        nums.push_back(101);
        // if(nums.size() >1 and nums[0] < nums[1])    lMax = nums[0];
        for(int i = 0 ; i <nums.size()-1 ; i++ ){
            if(nums[i+1] > nums[i]){
                lMax += nums[i];
            }else{
                lMax += nums[i];
                if(lMax > curMax)   curMax = lMax;
                lMax = 0;
            }
            if(lMax > curMax)   curMax = lMax;
        }

        return curMax;
    }
};