class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0 , r , n,ans = 0 ;
        n= height.size();
        r = n-1;
        int lBar = height[l] ,rBar = height[r];
        while(l<r){
            if(rBar > lBar){
                ans += lBar - height[l];
                ++l;
                lBar = max(lBar,height[l]);
            }else{
                ans += rBar - height[r];
                --r;
                rBar = max(rBar,height[r]);
            }
        }
        return ans;
    }
};