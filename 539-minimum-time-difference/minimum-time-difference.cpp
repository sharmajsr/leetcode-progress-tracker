class Solution {
public:
    int convertToNumber(string s){
        int result = 0 ;
        for(auto i : s){
            result  = result *10 + i-'0';
        }
        return result;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int>timeStamps;
        int n = timePoints.size();
        for(int i=0;i<n;i++){
            string s = timePoints[i];
            // if(s == "00:00") timeStamps.push_back(1440);
            int hour = convertToNumber(s.substr(0,2));
            int minutes = convertToNumber(s.substr(3,2));
            int total_time = hour * 60 + minutes;
            // if(total_time > 1440)
            timeStamps.push_back(total_time);
            timeStamps.push_back(-1 * (1440-total_time));
        }
        sort(timeStamps.begin(),timeStamps.end());
        int ans = INT_MAX;
        for(int i=1;i<timeStamps.size();i++){
            int t1 = abs(timeStamps[i]-timeStamps[i-1]);
            int t2 = abs(timeStamps[i-1]-timeStamps[i]);
            cout<<i<<" "<<t1<<" "<<t2<<endl;
            ans = min(ans, min(t1,t2));
        }
        return ans;
    }
};