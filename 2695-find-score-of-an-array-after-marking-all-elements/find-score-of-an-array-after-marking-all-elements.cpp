class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long sum =0,n=nums.size() ; 
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        for(int i = 0;i<n;i++)   minHeap.push({nums[i],i});
        while(!minHeap.empty()){
            auto top = minHeap.top();
            
            minHeap.pop();
            if(vis[top.second] == 0 ){
                // cout<<top.first<<endl;
                sum += top.first;
                if(top.second == 0){
                    if(n>1) vis[top.second+1] =1;
                }else if(top.second == n-1){
                    vis[top.second-1] =1;
                }else{
                    vis[top.second+1] =1;
                    vis[top.second-1] =1;
                }
            }
        }
        return sum;
    }
};