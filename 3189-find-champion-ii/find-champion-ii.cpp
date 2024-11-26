class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>in(n,0);
        queue<int>q;
        vector<int>adj[101];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            ++in[edges[i][1]];
        }
        for(int i=0;i<n;i++){
            if(in[i] == 0 ){
                q.push(i);
            }
        }
        if(q.size() == 1 )  return q.front();
        // if(q.size() == 1 )
        return -1;
    }
};