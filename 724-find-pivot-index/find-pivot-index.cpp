class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tsum = 0 ,n=nums.size(),lsum=0;
        for(auto i : nums) tsum+=i;
        for(int i=0;i<n;i++){
            tsum -= nums[i];
            if(tsum == lsum)    return i;
            lsum += nums[i];
        }
        return -1;
    }
};