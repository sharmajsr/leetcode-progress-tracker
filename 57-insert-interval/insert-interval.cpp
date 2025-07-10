class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0 ;
        vector<vector<int>>ans;
        while(i < n and intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i+=1;
        }
        // cout<<"left : " <<ans.size()<<" "<<i<<endl;
        while(i < n and intervals[i][0] <= newInterval[1]  ){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i+=1;
        }
        
        ans.push_back(newInterval);
        // cout<<"right : " <<ans.size()<<" "<<newInterval[0]<<" "<<newInterval[1]<<" "<<i<<endl;
        while(i < n){
            ans.push_back(intervals[i]);
            ++i;
        }

        return ans;
    }
};

// start
// 1
// 6

// End
// 3
// 9