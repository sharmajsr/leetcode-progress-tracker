class Solution {
public:
    int trap(vector<int>& he) {
        int ans= 0, n= he.size();;
        vector<int>lH(n,0);
        vector<int>rH(n,0);
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi =max(maxi,he[i]);
            lH[i] = maxi;
        }
        maxi =0 ;
        for(int i=n-1;i>=0;i--){
            maxi =max(maxi,he[i]);
            rH[i] = maxi;
        }
        for(int i=0;i<n;i++){
            ans += min(rH[i],lH[i])-he[i];
        }
        return ans;
    }
};