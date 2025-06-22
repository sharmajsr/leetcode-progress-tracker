class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ,ans =0 ;
        // vector<int>left(n,0);
        // vector<int>right(n,0);
        // int temp = height[0];
        // for(int i = 0 ; i<n ; i++){
        //     temp = max(temp,height[i]);
        //     left[i]=temp;
        // } 
        // temp = height[n-1] ;
        // for(int i=n-1 ; i>=0 ; i--){
        //     temp = max(temp,height[i]);
        //     right[i]=temp;
        // }
        // for(int i=1;i<n-1;i++){
        //     ans += min(left[i],right[i])-height[i];
        // }
        // return ans;
        int left = 0 , right = n-1;
        int leftBar = height[left] , rightBar = height[right];
        while(left < right){
            if(leftBar < rightBar){
                ans += leftBar - height[left];
                ++left;
                leftBar = max(leftBar,height[left]);
            }else{
                ans += rightBar - height[right];
                --right;
                rightBar = max(rightBar,height[right]);
            }
        }
        return ans;
    }
};

// arr -> 0,1, 0, 2,1,0,1,3,2,1,2,1
// left > 0,1, 1, 2,2,2,2,3,3,3,3,3
// right> 3,3, 3, 3,3,3,3,3,2,2,2,1
// ans. > 0 -1 0  