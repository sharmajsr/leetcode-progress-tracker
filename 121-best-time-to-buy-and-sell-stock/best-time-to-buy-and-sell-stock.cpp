class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0 ,n = prices.size();
        vector<int>rMax (n,0);
        int mini= prices[0];

        for(int i=0;i<n;i++){
            int cost = prices[i] -mini;
            ans = max(ans,cost);
            mini = min(mini,prices[i]);
        }
        return ans;
    }
};