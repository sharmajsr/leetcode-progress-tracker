class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>maxH;
        for(auto i : nums)  maxH.push(i);
        while( maxH.size() != k)    maxH.pop();
        return maxH.top();
    }
};