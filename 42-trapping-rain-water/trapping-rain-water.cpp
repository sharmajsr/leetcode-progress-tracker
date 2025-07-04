class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ,ans =0 ;
        vector<int>left(n,0),right(n,0);
        left[0]=height[0];
        for(int i= 1 ;i < n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        right[n-1] = height[n-1];
        for(int i= n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=1;i<n-1;i++){
            if( height[i] < min(left[i],right[i])){
                ans += min(left[i],right[i]) -height[i];
            }
        }
        return ans;
        
    }
};

// arr -> 0,1, 0, 2,1,0,1,3,2,1,2,1
// left > 0,1, 1, 2,2,2,2,3,3,3,3,3
// right> 3,3, 3, 3,3,3,3,3,2,2,2,1
// ans. > 0 -1 0  