class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>minCoins(amount+1,0);
        for(int i=1;i<=amount;i++){
            minCoins[i] = INT_MAX-1;
            for(int coin : coins){
                if(i >= coin and minCoins[i-coin] != INT_MAX-1)   
                    minCoins[i] = min(minCoins[i] , 1 + minCoins[i-coin]);
            }
        }
        return minCoins[amount] == INT_MAX-1 ? -1 : minCoins[amount];

    }
};