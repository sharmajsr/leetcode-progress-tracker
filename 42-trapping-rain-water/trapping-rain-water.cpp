class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()  <=1  )    return 0;
        int left = 0 ;
        int ans = 0;
        int right = height.size()-1;
        int leftBar = height[left];
        int rightBar = height[right];
        while(left<=right && right>=0 && left< height.size()){
            if(leftBar >= rightBar){
                cout<<"rightBar \n";
                ans += rightBar - height[right];
                right--;
                if(right >= 0 && height[right] > rightBar){
                    rightBar = height[right];
                }
            }
            else{
                cout<<"leftBar \n";
                ans += leftBar - height[left];
                left++;
                if(left <height.size() && height[left] > leftBar){
                    leftBar = height[left];
                }
            }
        }
        return ans;
    }
};