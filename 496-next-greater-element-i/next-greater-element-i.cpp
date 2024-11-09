class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<pair<int,int>>st;
        int n= nums2.size();
        vector<int>ans;
        unordered_map<int,int>um;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({nums2[i],i});
            }
            else if(st.top().first >= nums2[i]){
                st.push({nums2[i],i});
            }
            else{
                while(!st.empty() and st.top().first < nums2[i]){
                    auto top = st.top();
                    st.pop();
                    um[top.first] = nums2[i];
                }
                st.push({nums2[i],i});
            }
        }
        while(!st.empty()){
             auto top = st.top();
            st.pop();
            um[top.first] = -1;
        }
        for(auto i : nums1){
            ans.push_back(um[i]);
        }
        return ans;
        
    }
};