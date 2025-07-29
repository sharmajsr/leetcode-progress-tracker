class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(auto iv : intervals){
            if(ans.empty() or ans.back()[1] < iv[0]){
                ans.push_back(iv);
            }else{
                ans.back()[1] = max(ans.back()[1], iv[1]);
            }
        }
        return ans;
    }
};