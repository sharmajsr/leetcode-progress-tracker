class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        // stack<int>st;
        int lastEl =  nums[0];
        int n = nums.size(),cnt = 1;
        for(int i=1;i<n;i++){
            if(nums[i]>=lastEl){
                lastEl = nums[i];
                ++cnt;
            }
        }
        return cnt;
    }
};