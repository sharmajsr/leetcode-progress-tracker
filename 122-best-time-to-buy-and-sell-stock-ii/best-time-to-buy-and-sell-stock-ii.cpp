class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int ans= 0 ,n = prices.size(),i=0;
        while(i<n-1){
            if(prices[i+1]>prices[i]){
                int buyPrice = prices[i];
                while( i<n-1 && prices[i+1] > prices[i]){
                    ++i;
                }
                // cout<<buyPrice<<" "<<prices[i+1]<<" " <<i+1<<endl;
                ans += prices[i] - buyPrice;
            }
            ++i;
        }
        return ans;
    }
};