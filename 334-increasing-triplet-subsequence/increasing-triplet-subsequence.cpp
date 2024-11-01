class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis(n,1);
        // stack<pair<int,int>>st;
        // vector<int>dis(n,-1);
        // for(int i=0;i<n;i++){
        //     if(!st.empty()) st.push({nums[i],i});
        //     if(nums[i] > st.top().first){
        //         while(!st.empty() and nums[i] > st.top().first){
        //             pair<int,int>top = st.top();
        //             dis[top.second] = i;
        //         }
        //         st.push({nums[i],i});
        //     }else{
        //         st.push({nums[i],i});
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     for(int j= 0; j<i;j++){
        //         if(nums[j] >= nums[i])  continue;
        //         else    lis[i] = max(lis[i], 1+ lis[j]);
        //         if(lis[i] == 3) return true;
        //     }
        // }
        int left = INT_MAX, mid = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i] > mid)   return true;

            if(nums[i] > left and nums[i] <mid)  mid = nums[i];
            else if(nums[i] < left)  left = nums[i];
            
        }
        return false;
    }
};