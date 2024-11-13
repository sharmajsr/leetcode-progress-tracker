class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),ans= 0;
        int l=0,r=n-1;
        int lBar =height[l],rBar =height[r];
        while(l < r){
            if(lBar < rBar){
                ans += lBar - height[l];
                ++l;
                lBar = max(lBar,height[l]);
            }
            else{
                ans += rBar - height[r];
                --r;
                rBar = max(rBar,height[r]);
            }
        }
        return ans;
    }
};