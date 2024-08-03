class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 ) return 0;
        int a = INT_MIN , b = 0;
        int c = INT_MIN ,d = 0 ;
        for(auto i:prices){
            a = max(a, -i);
            b = max(b, a+i);
            c = max(c, b-i);
            d = max(d, c+i);
        }
        return d;
    }
};