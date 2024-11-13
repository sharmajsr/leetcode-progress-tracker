class Solution {
public:
    vector<int>findNSE(vector<int>nums){
        int n=nums.size();
        stack<pair<int,int>>st;
        // vector<pair<int,int>>nse(n,0);
        vector<int>nse(n,0);
        for(int i= 0;i<n;i++){
            if(st.empty()){
                st.push({nums[i],i});
            }else if(!st.empty() and nums[i] >= st.top().first  ){
                st.push({nums[i],i});
            }
            else if(!st.empty() and nums[i] < st.top().first){
                while(!st.empty() and nums[i] < st.top().first){
                    auto top = st.top();
                    st.pop();
                    nse[top.second]=i;
                }
                st.push({nums[i],i});
            }
        }
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            nse[top.second]= n;
        }
        return nse;
    }

    vector<int>findPSE(vector<int>& heights){
        int n=heights.size();
        stack<pair<int,int>>st;
        // vector<pair<int,int>>nse(n,0);
        vector<int>pse(n,0);
        for(int i=0;i<n;i++){
            if(st.empty()){
                pse[i]=-1;
                st.push({heights[i],i});
            }
            else if(!st.empty() and st.top().first >= heights[i]){
                while(!st.empty() and st.top().first >= heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    pse[i]=-1;
                }
                else if(!st.empty()){
                    pse[i] = st.top().second;
                }
                st.push({heights[i],i});
            }
            else if(!st.empty() and st.top().first < heights[i]){
                pse[i]=st.top().second;
                st.push({heights[i],i});
            }
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size(),ans =0;


        vector<int>nse,pse;
        nse= findNSE(heights);
        pse = findPSE(heights);
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<nse[i]<<" "<<pse[i]<<endl;
            ans = max(ans, heights[i] *(nse[i]-pse[i]-1));
        }
        // for(int i=0;i<n;i++){
        //     int curHeight = heights[i];
        //     int left = i,right=i;;
        //     while(left >=0 and heights[left] >= curHeight){
        //         --left;
        //     }
        //     while(right < n and heights[right] >= curHeight){
        //         ++right;
        //     }
        //     // cout<<left<<" "<<i<<" "<<right<<" "<<curHeight<<" "<<(right-left-1) * curHeight<<endl;
        //     ans = max(ans,(right-left-1) * curHeight);
        // }
        return ans;
    }
};