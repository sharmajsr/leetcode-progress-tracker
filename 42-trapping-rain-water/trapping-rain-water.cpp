class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0 , right =height.size()-1;
        int lBar = height[left],rBar = height[right];
        int ans = 0; 
        while(left<right){
            if( lBar < rBar){
                ans += lBar - height[left];
                left++;
                lBar = max(lBar,height[left]);
            }else{
                ans += rBar - height[right];
                right--;
                rBar = max(rBar,height[right]);
            }
        }
        return ans;
    }
};