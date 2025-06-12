class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int maxProfit = 0 , stockBuyPrice = prices[0],n = prices.size();
        for(int i= 0; i <n ; i++){
            maxProfit = max(maxProfit,prices[i]-stockBuyPrice);
            stockBuyPrice = min(prices[i],stockBuyPrice);
        }
        return maxProfit;
    }
};