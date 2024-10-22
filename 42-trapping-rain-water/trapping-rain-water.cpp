class Solution {
public:
    int trap(vector<int>& he) {
        int ans = 0 , n= he.size();
        int l = 0 , r= n-1 ;
        int lBar = 0, rBar = 0;
        while(l < r){
            if(he[l] <= he[r]){
                if(lBar >he[l]){
                    ans += (lBar-he[l]);
                }
                else{
                    lBar = he[l];
                }
                ++l;
            }
            else{
                if(rBar > he[r]){
                    ans += (rBar - he[r]);
                }else{
                    rBar = he[r];
                    
                }
                --r;
            }
        } 
        return ans;
    }
};