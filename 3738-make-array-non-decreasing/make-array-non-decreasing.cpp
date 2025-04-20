class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int>st;
        int n = nums.size(),cnt = 0,runningSmall = 0 ;
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>=st.top()){
               st.push(nums[i]);
            }
        }
        return st.size();
    }
};