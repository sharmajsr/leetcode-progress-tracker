class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int left = 0 , right = n-1 ,ans = 0;
        int leftBar = height[left], rightBar = height[right];
        while(left<right){
            if(leftBar < rightBar){
                ans += (leftBar - height[left]);
                ++left;
                leftBar = max(leftBar,height[left]);
            }else{
                ans += (rightBar - height[right]);
                --right;
                rightBar = max(rightBar,height[right]);
            }
        }
        return ans;
    }
};