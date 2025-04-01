class Solution {
public:
    long long solve(vector<vector<int>>& questions,int idx,vector<long long>&dp){
        if(idx >= questions.size()){
            return 0;
        }
        if(dp[idx] != -1)   return dp[idx];
        long long take = questions[idx][0] + solve(questions,idx+1+questions[idx][1],dp);
        long long not_take = solve(questions,idx+1,dp);
        return dp[idx] = max(take,not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(1e6,-1);
        solve(questions,0,dp);
        return dp[0];
    }
};