class Solution {
public:
    vector<int> findNSE(vector<int> heights){
        
        stack<pair<int,int>>st;
        
        int n= heights.size();
        vector<int>ans(n,0);
        for(int i=0; i <n;i++){
            if(st.empty()){
                st.push({heights[i],i});
                
            }else if(!st.empty() and st.top().first > heights[i]){
                while(!st.empty() and st.top().first > heights[i]){
                    auto top=st.top();
                    st.pop();
                    ans[top.second] = i ;
                }
                st.push({heights[i],i});
            }else{
                st.push({heights[i],i});
            }
        }
        while(!st.empty()){
            ans[st.top().second]=n;
            st.pop();
        }
        return ans;

    }
    vector<int> findPSE(vector<int>heights){
        stack<pair<int,int>>st;
        int n= heights.size();
        
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({heights[i],i});
            }
            else if(!st.empty() and st.top().first < heights[i]){
                ans[i]=st.top().second+1;
                st.push({heights[i],i});
            }else if(!st.empty() and st.top().first >= heights[i]){
                while(!st.empty() and st.top().first >= heights[i]){
                    // ans[st.top().second]=
                    st.pop();
                }
                if(st.empty()){
                    st.push({heights[i],i});
                }else if(!st.empty()){
                    ans[i]=st.top().second+1;
                    st.push({heights[i],i});
                }
            }
        }
        // while(!st.empty()){
        //     ans[st.top().second]=0;
        //     st.pop();
        // }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0 ;
        if( heights.size() == 1 ) return heights[0];
        vector<int>ns = findNSE(heights);
        vector<int>ps = findPSE(heights);
        for(int i=0;i<heights.size();i++){
            ans = max(ans,heights[i]*(ns[i]-ps[i]));
            // cout<<i<<" "<<heights[i]<<" "<<ns[i]<<" "<<ps[i]<<endl; 
        }
        return ans;
    }
};