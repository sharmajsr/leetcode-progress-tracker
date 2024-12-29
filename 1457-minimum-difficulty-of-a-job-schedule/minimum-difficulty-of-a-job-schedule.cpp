class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jobDifficulty, int n, int idx, int d) {
        
        // If you have only 1 day, then you will do all the remaining jobs
        // and select the max difficulty as the answer
        if (d == 1) {
            // return *max_element(begin(jobDifficulty) + idx, end(jobDifficulty));
            int maxD = jobDifficulty[idx];
            for(int i = idx ;i < n; i++){
                maxD= max(maxD,jobDifficulty[i]);
            }
            return t[idx][d]=maxD;
        }
        
        if (t[idx][d] != -1)
            return t[idx][d];
    
        int Max = INT_MIN;
        int result = INT_MAX;
        
        // Try one by one with all possibilities
        /*
            Take 1 job in one day
            Take 2 jobs in one day
            Take 3 jobs in one day
            and so on
            
            Then find the optimal one among all the results
        */
        for (int i = idx; i <= n - d; i++) {
            // Max = max(Max, jobDifficulty[i]);
            // result = min(result, Max + solve(jobDifficulty, n, i + 1, d - 1));

            Max = max(Max,jobDifficulty[i]);
            int fresult = Max + solve(jobDifficulty, n, i + 1, d - 1);
            // cout<<idx<<" "<<d<<" "<<jd[i]<< " "<<result<<endl; 
            result = min(result, fresult);
        }
        
        return t[idx][d] = result;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if (n < d)
            return -1;

        memset(t, -1, sizeof(t));
        
        return solve(jobDifficulty, n, 0, d);
    }
};