class Solution {
public:
    int rob(vector<int>& nums) {
        int r1 = 0 ,r2= 0;
        for(int i=0;i<nums.size();i++){
            int temp = max(nums[i] + r2,r1);
            r2=r1;
            r1=temp;
        }
        return max(r2,r1);
    }
};