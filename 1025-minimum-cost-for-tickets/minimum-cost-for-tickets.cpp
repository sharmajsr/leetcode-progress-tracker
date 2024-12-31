class Solution {
public:
vector<int>dp;
int solve(vector<int>cost,vector<int>days,int idx){
    int n = days.size();
    if(idx == n){
        return 0;
    }
    if(dp[idx]!=-1) return dp[idx];
    auto lb2 = lower_bound(days.begin(), days.end(), days[idx]+7);
    auto lb3 = lower_bound(days.begin(), days.end(), days[idx]+30);

    int cost0 = cost[0] + solve(cost,days,idx+1);
    int cost1 = cost[1] + solve(cost,days,(lb2-days.begin()));
    int cost2 = cost[2] + solve(cost,days,(lb3-days.begin()));

    return dp[idx]=min(cost0,min(cost1,cost2));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(366,-1);
        return solve(costs,days,0);
    }
};