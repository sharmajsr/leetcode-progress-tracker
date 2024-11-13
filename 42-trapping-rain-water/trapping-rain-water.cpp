class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(),ans =0 ;
        vector<int>lH(n,0),rH(n,0);
        int mini = INT_MIN;
        for(int i=0;i<n;i++){
            mini = max(mini,height[i]);
            lH[i]=mini;
        }
        mini = INT_MIN;
        for(int i=n-1;i>=0;i--){
            mini = max(mini,height[i]);
            rH[i]=mini;
        }
        for(int i=0;i<n;i++){
            ans+=min(rH[i],lH[i])-height[i];

        }
        return ans;
    }
};