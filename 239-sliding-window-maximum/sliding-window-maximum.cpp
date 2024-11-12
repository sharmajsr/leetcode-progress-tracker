class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        priority_queue<pair<int,int>>maxH;
        for(int i=0;i<k;i++){
            maxH.push({nums[i],i});
        }
        cout<<maxH.size()<<endl;
        for(int i=k-1;i<n;i++){
            // cout<<i<<" "<<maxH.size()<<endl;
            
            maxH.push({nums[i],i});
            while(!maxH.empty() and maxH.top().second < (i-k+1)){
                maxH.pop();
            }
            ans.push_back(maxH.top().first);
        }
        // if(!maxH.empty() and maxH.top().second < (n-k+1)){
        //         maxH.pop();
        // }
        // ans.push_back(maxH.top().first);
        return ans;
    }
};