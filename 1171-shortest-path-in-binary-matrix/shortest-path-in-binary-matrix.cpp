class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        pair<int,int>source = {0,0};
        int n = grid.size() , m = grid[0].size();
        pair<int,int>dest={n-1,m-1};
        vector<vector<int>>ans(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{source.first,source.second}});
        ans[source.first][source.second] = 0;
        while(!pq.empty()){
            auto fr =pq.top();pq.pop();
            int dis = fr.first;
            int row = fr.second.first;
            int col = fr.second.second;
            for(int i=-1 ; i<=1 ; i++){
                for(int j= -1; j<=1 ;j++){
                    if(i ==0 and j== 0) continue;
                    int nr = row + i;
                    int nc = col + j;
                    if(nr>=0 and nr < n and nc>=0 and nc< m and grid[nr][nc]==0 and ans[nr][nc] > ans[row][col] + 1 ){
                        ans[nr][nc] = ans[row][col] + 1;
                        pq.push({ans[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        if(ans[dest.first][dest.second] == 1e9) return -1;
        return ans[dest.first][dest.second]+1;
    }
};