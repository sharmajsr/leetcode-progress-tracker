class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int>maxHeap;
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int dis = abs(queries[i][0]) + abs(queries[i][1]);
            maxHeap.push(dis);
            if(maxHeap.size() >= k) {
                while(!maxHeap.empty() && maxHeap.size() >k ){
                    maxHeap.pop();
                }
                ans.push_back(maxHeap.top());
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

// 5 -1
// 7,5 -> 7
// 7,5,5, -> 