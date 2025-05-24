class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n,0),right(n,0);
        int temp = nums[0] ,ans = INT_MAX;
        left[0] = temp;
        right[n-1] = nums[n-1];
        for(int i = 1;i<nums.size();i++){
            left[i] = min(left[i-1],nums[i]);
        }
        for(int i= nums.size()-2 ;i >= 0 ;i--){
            right[i] = min(right[i+1],nums[i]);
        }
        for(int i=1; i<n-1;i++){
            if(nums[i] > left[i-1] and nums[i]>right[i+1]){
                ans = min(ans,nums[i] + left[i-1] + right[i+1]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};