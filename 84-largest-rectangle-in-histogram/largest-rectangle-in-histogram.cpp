class Solution {
public:
    vector<int> findNSE(vector<int>&heights){
        stack<pair<int,int>>st;
        int n= heights.size();
        vector<int>left(n,0);
        for(int i = 0 ; i < n ; i++){
            if(st.empty()){
                st.push({heights[i],i});
            }else if(!st.empty() and st.top().first <= heights[i]){
                st.push({heights[i],i});
            }else if(!st.empty() and heights[i] < st.top().first){
                while(!st.empty() and heights[i] < st.top().first){
                    left[st.top().second]=i;
                    st.pop();
                }
                st.push({heights[i],i});
            }
        }

        
        while(!st.empty()){
            left[st.top().second]=n;
            st.pop();
        }
        return left;
    
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
    vector<int>findPSE1(vector<int>&heights){
        stack<pair<int,int>>st;
        int n= heights.size();
        vector<int>right(n,0);
        right[0]=-1;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({heights[i],i});
            }else if(!st.empty() and st.top().first <= heights[i]){
                right[i]=st.top().second;
                st.push({heights[i],i});
            }else if(!st.empty() and st.top().first > heights[i]){
                while(!st.empty() and st.top().first > heights[i]){
                    st.pop();
                }
                // if(!st.empty()){
                //     right[i]=st.top().second;
                // }
                st.push({heights[i],i});
            }
        }
        while(!st.empty()){
            right[st.top().second] = -1;
            st.pop();
        }
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans =0 , n= heights.size();
        vector<int>left = findNSE(heights);
        vector<int>right = findPSE(heights);
        for(int i=0;i<n;i++){
            // int j=i-1 , k = i+1;
            // while(j>=0 and heights[j]>=heights[i]){
            //     --j;
            // }
            // while(k<n and heights[i] <= heights[k]){
            //     ++k;
            // }
            // cout<<i<<" "<<left[i]<<" "<<right[i]<<endl;
            int temp = heights[i]*(left[i]-right[i]);
            ans = max(temp,ans);
            
        }

        return ans;
    }
};