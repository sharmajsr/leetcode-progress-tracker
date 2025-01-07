class Solution {
public:
int dp[50005];
    int findNextIdx(vector<vector<int>>&all,int curTime,int low){
        int high = all.size()-1;

        int result = all.size()+1; 

        while(low<=high){
            int mid = (low + high)/2;
            if( all[mid][0] >= curTime ){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>&all,int idx){
        if(idx >= all.size()){
            return 0;
        }
        if(dp[idx] != -1)    return dp[idx];
        int next = findNextIdx(all , all[idx][1] , idx+1);

        
        int taken = all[idx][2] + solve(all,next);
        int nottaken = solve(all,idx+1);

        return dp[idx] =  max(taken,nottaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>all(startTime.size(),vector<int>(3,0));
        // dp.resize(50005,-1);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<startTime.size();i++){
            vector<int>temp;
            temp.push_back(startTime[i]);
            temp.push_back(endTime[i]);
            temp.push_back(profit[i]);
            all[i]=temp;
        }
        sort(all.begin(),all.end());
        return solve(all,0);
    }
};