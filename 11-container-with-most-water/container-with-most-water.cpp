class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size() , left = 0 ;
        int right = n-1 , ans= 0 ;
        vector<int>lMax(n,0), rMax(n,0);
        lMax[0]   = height[0];
        rMax[n-1] = height[n-1];
        for(int i = 1 ; i<n ; i++){
            lMax[i] = max(lMax[i-1],height[i]);
        }
        for(int i = n-2 ; i >= 0 ; i-- ){
            rMax[i] = max(rMax[i+1],height[i]);
            cout<<i<<" "<<rMax[i]<<endl;
        }
        while(left<=right){
            int dis = right- left;
            int minH = min(lMax[left],rMax[right]);
            ans = max(ans, dis*minH);
            if(lMax[left] > rMax[right])    --right;
            else ++left;
        }
        return ans;
        
    }
};
// 1,8,6,2,5,4,8,3,7
// 1 8 8 8 8 8 8 8 8
// 8 8 8 8 8 8 8 7 7 
// [8,7,2,1]
//  8 8 8 8
//  8 7 2 1
// 