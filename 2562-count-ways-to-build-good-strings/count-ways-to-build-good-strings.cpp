class Solution {
public:
    vector<int>dp;
    int MOD = 1e9+7;
    int solve(int low,int high,int zero,int one ,int d1){
        if(d1 > high){
            return 0;
        }
        if(dp[d1]!=-1)   return dp[d1];
        int d = 0;
        if(d1>=low) d=1;
        d += ( solve(low,high,zero,one,d1+zero) + solve(low,high,zero,one,d1+one));
        return dp[d1]=d % MOD;
    }
    int countGoodStrings(int low, int high, int numZero, int numOne) {
        dp.resize(high+1,-1);
        return solve(low,high,numZero,numOne,0);
    }
};