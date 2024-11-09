class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        stack<pair<int,int>>st;

        for(int i=0;i<n;i++){
            if(st.empty())  st.push({nums[i],i});
            else if(!st.empty() and st.top().first >= nums[i]){
                st.push({nums[i],i});
            }
            else if( !st.empty() and st.top().first < nums[i]) {
                while(!st.empty() and st.top().first < nums[i] ){
                    pair<int,int>top = st.top();
                    st.pop();
                    ans[top.second] = nums[i];
                }
                st.push({nums[i],i});
            }
        }
        if(!st.empty()){
            for(int i=0;i<n;i++){
                if(!st.empty() and nums[i] > st.top().first){
                    while(!st.empty() and nums[i] > st.top().first){
                        auto top = st.top();
                        st.pop();
                        ans[top.second]=nums[i];
                    }
                }
            }
        }
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            ans[top.second]=-1;
        }
        
        return ans;
    }
};