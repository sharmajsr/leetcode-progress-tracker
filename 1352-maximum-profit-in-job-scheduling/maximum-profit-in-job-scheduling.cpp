class Solution {
public:
int dp[50005];
    int findNextIdx(vector<pair<int,pair<int,int>>>&all,int curTime,int low){
        int high = all.size()-1;

        int result = all.size()+1; 

        while(low<=high){
            int mid = (low + high)/2;
            if( all[mid].first >= curTime ){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
    int solve(vector<pair<int,pair<int,int>>>&all,int idx){
        if(idx >= all.size()){
            return 0;
        }
        if(dp[idx] != -1)    return dp[idx];
        int next = findNextIdx(all , all[idx].second.first , idx+1);
        // cout<<idx+1<<" "<<all[idx].first<<" "<<all[idx].second.first<<" "<<all[idx].second.second<<endl;
        
        int taken = all[idx].second.second + solve(all,next);
        int nottaken = solve(all,idx+1);

        return dp[idx] =  max(taken,nottaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,pair<int,int>>>all;
        // dp.resize(50005,-1);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<startTime.size();i++){
            all.push_back({startTime[i],{endTime[i],profit[i]}});
        }
        sort(all.begin(),all.end());
        return solve(all,0);
    }
};