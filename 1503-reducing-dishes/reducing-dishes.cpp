class Solution {
public:
    int solve(vector<int>sat,int idx,int cnt,vector<vector<int>>dp){
        if(idx == 1)  return dp[idx][cnt] = cnt*max(sat[idx-1],0) ;
        if(dp[idx][cnt] != -1)  return dp[idx][cnt];
        int pick = cnt * sat[idx-1] + solve(sat,idx-1,cnt+1,dp);
        int not_pick = solve(sat,idx-1,cnt,dp);
        return dp[idx][cnt] = max(pick,not_pick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end(),greater<int>());
 
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1 ; i <=n ;i++)   dp[1][i] = i*max(satisfaction[0],0);

        for(int idx=2;idx<=n;idx++){
            for(int cnt = n -1; cnt>= 1 ;cnt-- ){
                int pick = cnt * satisfaction[idx-1] + dp[idx-1][cnt+1];
                int not_pick = dp[idx-1][cnt];
                dp[idx][cnt] = max(pick,not_pick);
            }
        }
        
        return dp[n][1];
    }
};