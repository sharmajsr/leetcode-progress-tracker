class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n =heights.size() , m = heights[0].size();
        int rows[] = {0,0,1,-1} , cols[] = {1,-1,0,0} ;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto tp = pq.top(); pq.pop();
            int currDif = tp.first;
            int row = tp.second.first;
            int col = tp.second.second;
            for(int i= 0; i <4; i++){
                int nr = row + rows[i];
                int nc = col + cols[i];
                if(nr >=0 and nr < n and nc>=0 and nc < m){
                    int maxDiff = max(currDif, abs(heights[nr][nc]-heights[row][col]));
                    if(dis[nr][nc] > maxDiff){
                        dis[nr][nc] = maxDiff;
                        pq.push({maxDiff,{nr,nc}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};