class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans = 0 , n = a.size(),i=1;
        while(i<n){
            if(a[i]>a[i-1]){
                ans+= a[i]-a[i-1];
            }
            ++i;
        }
        return ans;
    }
};