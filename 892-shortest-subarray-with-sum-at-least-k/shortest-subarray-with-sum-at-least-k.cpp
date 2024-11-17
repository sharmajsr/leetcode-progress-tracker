class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long n= nums.size(),min_subarray = INT_MAX;
        long long i = 0, j =0, sum=0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>minHeap;

        for(int j=0;j<n;j++){
            sum+= nums[j];
            if(sum>=k and min_subarray > j+1){
                min_subarray = j+1;
            }
            while(!minHeap.empty() and (sum - minHeap.top().first) >=k){
                auto top = minHeap.top();
                long long el = top.first;
                long long pos = top.second;
                if(min_subarray > j-pos){
                    min_subarray =j-pos;
                }
                // min_subarray = min(min_subarray,j-pos);
                minHeap.pop();
            }
            minHeap.push({sum,j});
            // ++j;
        }
        return min_subarray == INT_MAX ? -1 : min_subarray ;
    }
};