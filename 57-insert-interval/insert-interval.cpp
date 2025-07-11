class Solution {

public:
    static bool compareIntervals(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> all = intervals;
        all.push_back(newInterval);

        // 3. Sort using our named function
        sort(all.begin(), all.end(), compareIntervals);

        // 4. Merge pass
        vector<vector<int>> merged;
        for (auto& iv : all) {
            if (merged.empty() || merged.back()[1] < iv[0]) {
                merged.push_back(iv);
            } else {
                merged.back()[1] = max(merged.back()[1], iv[1]);
            }
        }
        return merged;
    }
};
