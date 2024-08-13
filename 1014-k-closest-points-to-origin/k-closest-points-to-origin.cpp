class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<long long,vector<int>>>maxHeap;
        for(auto i : points){
            long long dis = ( (i[0] * i[0]) + (i[1]*i[1]) );
            maxHeap.push({dis,i});
            if(maxHeap.size() > k ) maxHeap.pop();
        }
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};