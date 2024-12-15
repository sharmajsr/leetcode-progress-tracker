class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>um;
        stack<int>st;
        
        for(auto i: nums2){
            if(st.empty()){
                st.push(i);
            }
            else if(!st.empty() and st.top() >= i){
                st.push(i);
            }
            else if(!st.empty() and i > st.top()){
                while(!st.empty() and i>st.top()){
                    um[st.top()] = i ;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            um[st.top()] = -1;
            st.pop();
        }
        for(auto i : nums1){
            ans.push_back(um[i]);
        }
        return ans;
    }   
};