class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>um;
        priority_queue<pair<int,int>>maxHeap;
        for(auto i : nums) ++um[i];
        for(auto i : um )   maxHeap.push({i.second,i.first});
        while(k-- and !maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};