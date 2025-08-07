class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuyDay= INT_MAX , n = prices.size() , ans = 0;
        for(int i= 0; i<n; i++){
            // cout<<i<<" "<<prices[i]<<" "<<minBuyDay<<" "<<ans<<endl; 
            ans = max(ans,  prices[i] - minBuyDay );
            minBuyDay = min(minBuyDay, prices[i]);
        }
        return ans;
    }
};