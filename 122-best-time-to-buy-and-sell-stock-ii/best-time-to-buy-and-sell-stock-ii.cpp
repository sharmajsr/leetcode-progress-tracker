class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int ans= 0 ,n = prices.size();
        for(int i=0;i<n-1;i++){
            if(prices[i+1]>prices[i]){
                int buyPrice = prices[i];
                while( i<n-1 && prices[i+1] > prices[i]){
                    ++i;
                }
                ans += prices[i] - buyPrice;
            }
            // ++i;
        }
        // for(i=0;i<n-1;i++){
        //     int temp = prices[i+1] - prices[i];
        //     if(temp > 0 ) ans+=temp;
        // }
        return ans;
    }
};