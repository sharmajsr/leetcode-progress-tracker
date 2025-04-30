class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int,vector<int>,greater<int>>minH;
        // for(auto i : nums){
        //     minH.push(i);
        // }
        // while(minH.size() > k){
        //     minH.pop();
        // }
        // return minH.top();
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};