class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        for(int i= 0 ; i<=n;i++){

            if(ans.empty() or ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] =  max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
// [ [1,3] , [2,5] ,[3,5] [6,9]    ],
// [ [1,3]           ]