class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int,vector<int>,greater<int>>minHeap;
        long long n = grid.size(),m=grid[0].size(),ans = 0;
        for(int i=0;i<n;i++){
            priority_queue< int, vector<int> , greater<int> >tempMinHeap;
            for(int j=0;j<m;j++){
                tempMinHeap.push(grid[i][j]);
                if(tempMinHeap.size() > limits[i]){
                    tempMinHeap.pop();
                }
            }
            // cout<<limits[i]<<" "<<tempMinHeap.size()<<" "<<tempMinHeap.top()<<endl;
            while(!tempMinHeap.empty()){
                minHeap.push(tempMinHeap.top());
                // cout<<i<<" <> "<<tempMinHeap.top()<<endl;
                // if(minHeap.size()>k){
                //     minHeap.pop();
                // }
                tempMinHeap.pop();
            }

        }
        // cout<<"MinHeap size. : " <<minHeap.size()<<endl;
        while(minHeap.size()>k) {
            // --k;
            minHeap.pop();
        }
        // cout<<"MinHeap size. : " <<minHeap.size()<<endl;
        while(!minHeap.empty()){
            cout<<minHeap.top()<<endl;
            ans += minHeap.top();
            minHeap.pop();
        }
        return ans;
        
    }
};