class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() , start = 0 ;
        k %= n;
        vector<int>v(nums.size(),0);
        for(int i= n-k;i<n;i++){
            v[start++] = nums[i];
        }
        for(int i= 0 ;i < n-k;i++){
            v[start++] = nums[i];
        }
        nums = v;
    }
};