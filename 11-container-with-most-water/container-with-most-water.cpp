class Solution {
public:
    int maxArea(vector<int>& height) {
        int j= 0 ; 
        int k=height.size()-1;
        int ans = INT_MIN;
        while(j<k){
            int h = height[j]> height[k] ? height[k] : height[j] ;
            int dis = k-j;
            ans = max(ans , dis * h);
            if( h == height[j] ){
                ++j;
            }
            else {
                --k;
            }
            
        }
        return ans;
    }
};