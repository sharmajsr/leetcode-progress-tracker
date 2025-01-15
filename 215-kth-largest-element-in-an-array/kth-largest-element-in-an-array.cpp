class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxh;
        for(auto i : nums){
            maxh.push(i);
        }
        k-=1;
        while(k--){
            maxh.pop();
        }
        return maxh.top();
    }
};