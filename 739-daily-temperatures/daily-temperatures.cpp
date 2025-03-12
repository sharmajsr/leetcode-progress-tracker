class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>v(n,0);
        stack<pair<int,int>>st;
        for(int i= 0 ; i < n; i++){
            if(st.empty()){
                st.push({temp[i],i});
            }else if(!st.empty() and st.top().first >= temp[i]){
                st.push({temp[i],i});
            }else if(!st.empty() and st.top().first < temp[i]){
                while(!st.empty() and st.top().first < temp[i]){
                    auto top = st.top();
                    st.pop();
                    v[top.second]=  i - top.second;
                }
                st.push({temp[i],i});
            }
        }
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            v[top.second]=  0;
        }

        return v;
    }
};