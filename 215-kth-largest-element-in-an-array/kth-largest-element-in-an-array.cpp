class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans;
        priority_queue<int>maxHeap;
        for(auto i : nums) maxHeap.push(i);
        while(!maxHeap.empty() and k--){
            ans = maxHeap.top();
            maxHeap.pop();
        }
        return ans;
    }
};