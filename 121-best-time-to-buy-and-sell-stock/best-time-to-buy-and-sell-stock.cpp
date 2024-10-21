class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),ans= 0;
        int maxPrice = prices[n-1];
        for(int i=n-1;i>=0;i--){
            if(prices[i] > maxPrice){
                maxPrice = prices[i];
            }
            ans = max(ans,maxPrice - prices[i]);
        }
        return ans;
    }
};