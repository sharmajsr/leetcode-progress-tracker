class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[1002];
        for(auto i : times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>vis(n+1,0);
        vector<int>dis(n+1,1e9);
        int maxT = 0 ;
        queue<pair<int,int>>q;
        q.push({k,0});
        dis[k]=0;
        while(!q.empty()){
            int fr   = q.front().first ;
            int dist = q.front().second;
            // cout<<fr<<" "<<dist<<endl;
            q.pop();
            for(auto it : adj[fr]){
                int node = it.first;
                if(dis[node] > dist + it.second){
                    vis[node]=true;
                    dis[node] = dist + it.second;
                    q.push({node,dis[node]});
                }
            }
        }
        bool notFound = false;
        for(int i=1 ; i <= n; i++){
            // cout<<i<<" "<<vis[i]<<" "<<dis[i]<<endl;
            if(vis[i] == 0 and i!=k){
                notFound = true;
            }
            maxT = max(maxT, dis[i]);
        }
        if(notFound){
            return -1;
        }
        return maxT;
    }
};