class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ,ans =0 ;
        int l = 0, r = n-1;
        int leftBar = height[l] , rightBar = height[r];
        while(l<r){
            if(leftBar < rightBar){
                ans += leftBar - height[l];
                ++l;
                leftBar = max(leftBar,height[l]);
            }else{
                ans += rightBar - height[r];
                --r;
                rightBar = max(rightBar,height[r]);
            }
        }
        return ans;
        
    }
};

// arr -> 0,1, 0, 2,1,0,1,3,2,1,2,1
// left > 0,1, 1, 2,2,2,2,3,3,3,3,3
// right> 3,3, 3, 3,3,3,3,3,2,2,2,1
// ans. > 0 -1 0  