class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st;
        int n = temp.size();
        vector<int>ans(n,0);
        for(int i= 0 ; i< n ;i++){
            // auto top = st.top();
            if(st.empty() ){
                st.push({temp[i],i});
            }
            else if(!st.empty() && st.top().first >= temp[i]){
                st.push({temp[i],i});
            }
            else if(!st.empty() && temp[i] > st.top().first){
                
                    while(!st.empty() && temp[i]>st.top().first){
                        // cout<<i<<" "<<st.top().first<<" " <<temp[i]<<endl;
                        ans[st.top().second] = i-st.top().second;
                        st.pop();
                    }
                    st.push({temp[i],i});
                }
        }
        while(!st.empty()){
            ans[st.top().second]=0;
            st.pop();
        }
        return ans;
    }
};