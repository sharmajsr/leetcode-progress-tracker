class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        bool ans = true;
        vector<int>freq(n+1,0);
        for(auto i : queries){
            int start = i[0];
            int end = i[1];
            --freq[start];
            ++freq[end+1];
        }
        for(int i=1;i<n;i++){
            freq[i] +=freq[i-1];
        }
        for(int i = 0; i < n;i++){
            if( (nums[i]+freq[i]) > 0 ){
                ans = false;
            }
        }
        return ans;
    }
};