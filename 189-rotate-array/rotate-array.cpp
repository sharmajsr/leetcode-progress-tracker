class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() ;
        k%=n;
        // reverse(nums.begin(),nums.end());
        // reverse(nums.begin(),nums.begin()+k);
        // reverse(nums.begin()+k,nums.end());
        vector<int>temp(n,0);
        int j = 0 ;
        for(int i=n-k ; i< n ; i++){
            temp[j++] = nums[i];
        }
        for(int i= 0; i< n-k;i++){
            temp[j++] = nums[i];
        }
        nums = temp;

    }
};