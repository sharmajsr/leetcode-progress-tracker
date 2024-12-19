class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0 , right =height.size()-1 , n = height.size();
        int lBar = height[left],rBar = height[right];
        int ans = 0 ,maxi = height[0]; 
        vector<int>leftM(n,0),rightM(n,0);
        for(int i=0;i<n;i++){
            maxi =max(height[i],maxi);
            leftM[i] = maxi;
        }
        maxi = height[n-1];
        for(int i=n-1;i>=0;i--){
            maxi =max(height[i],maxi);
            rightM[i] = maxi;
        }
        for(int i=0;i<n;i++){
            ans+= (min(leftM[i],rightM[i])- height[i]);
        }

        return ans;
    }
};