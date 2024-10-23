class Solution {
public:
    int trap(vector<int>& he) {
        int ans = 0 , n= he.size();
        int l = 0 , r= n-1 ;
        int lBar = he[l], rBar = he[r];
        while(l<r){
            if(lBar < rBar){
                ans+= (lBar -he[l]);
                ++l;
                lBar = max(lBar,he[l]);
            }else{
                ans+= (rBar - he[r]);
                --r;
                rBar = max(rBar,he[r]);
            }
        }
        
        return ans;
    }
};