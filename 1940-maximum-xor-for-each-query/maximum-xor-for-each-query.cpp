class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>prefix_xor;
        vector<int>ans;
        prefix_xor.push_back(nums[0]);
        for(int i = 1 ; i < n ;i++){
            prefix_xor.push_back(nums[i] ^ prefix_xor[i-1]);
            // cout<<i<<" "<<nums[i]<<" "<<prefix_xor[i]<<endl;
        }
        int maxK = pow(2,maximumBit)-1;
        for(int i=n-1 ; i>=0 ; i--){
            ans.push_back(prefix_xor[i] ^ maxK);
        }
        return ans;
    }
};