class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<
            pair<int,vector<int>>,
            vector< pair<int,vector<int>>>,greater<pair<int,vector<int>>>>minH;
        for(auto point: points){
            int x = point[0] , y = point[1];
            int dis = x*x + y*y;
            minH.push({dis,point});
        }
        while(!minH.empty() and k--){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};