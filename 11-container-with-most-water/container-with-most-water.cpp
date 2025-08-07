class Solution {
public:
    int maxArea(vector<int>& height) {
        int n =height.size();
        int i =0 , j= n-1 , maxAns = 0 ;
        while( i < j ){
            int dis = j-i;
            // cout<<i<<" "<<j<<" "<<dis<<" "<<height[i]<<" "<<height[j]<<" "<<maxAns<<endl;
            maxAns = max(maxAns, dis * min(height[j],height[i]));
            if(height[i] > height[j])   --j;
            else    ++i;
        }
        return maxAns;
    }
};