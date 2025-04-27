class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1)    return;
        int i = 0  ,  j = 0,   n = nums.size();

        while(j<n){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                ++i;
                ++j;
            }else{
                ++j;
            }
        }
    }
};
// ij
// 0   1   0   3   12

//    ij
// 1  2  0  0
// 