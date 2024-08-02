class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        k%=nums.size();
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
        
    }
};