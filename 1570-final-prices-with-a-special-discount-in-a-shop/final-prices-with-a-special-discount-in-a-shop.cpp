class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size() ;
        vector<int>discount(n,0),ans;
        stack<pair<int,int>>st;
        for(int i = 0 ; i < n ; i++){
            if(st.empty() || (!st.empty() and st.top().first < prices[i])){
                st.push( {prices[i],i});
            }else if(st.top().first >= prices[i]){
                while(!st.empty() and st.top().first >= prices[i]){
                    auto top = st.top();
                    st.pop();
                    discount[top.second]=prices[i];
                }
                st.push( {prices[i],i});
            }
        }
        for(int i=0;i<n;i++){
            ans.push_back(prices[i]-discount[i]);
        }
        return ans;
    }
};