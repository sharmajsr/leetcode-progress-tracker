class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<int> ans(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        for(int i=0;i<n;i++){
            minHeap.push({nums[i],i});
        }
        while(k--){
            auto top = minHeap.top();
            minHeap.pop();
            minHeap.push({top.first*multiplier,top.second});
        }
        while(!minHeap.empty()){
            ans[minHeap.top().second]=minHeap.top().first;
            minHeap.pop();
        }
        return ans;
    }
};