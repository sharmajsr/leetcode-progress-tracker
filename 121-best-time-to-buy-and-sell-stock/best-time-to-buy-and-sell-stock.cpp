class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0 ,n = prices.size();
        vector<int>rMax (n,0);
        int prevMax= prices[n-1];
        for(int i=n-1 ; i >= 0; i--){
            prevMax = max(prevMax ,prices[i]);
            rMax[i] = prevMax;
        }
        for(int i=0;i<n;i++){
            ans = max(ans, rMax[i]-prices[i]);
        }
        return ans;
    }
};