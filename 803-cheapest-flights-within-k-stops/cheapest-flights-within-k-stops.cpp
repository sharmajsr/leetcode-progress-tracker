class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>dis(n,1e9);
        unordered_map<int,pair<int,int>>um;
        pq.push({0,{src,0}});
        vector<pair<int,int>>adj[101];
        for(auto i : flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int curSteps = top.first;
            int node = top.second.first;
            int cst = top.second.second;
            if(curSteps > k )   continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int cost = it.second;
                if(dis[adjNode] > cost + cst){
                    dis[adjNode] = cost + cst;
                    pq.push({curSteps+1,{adjNode,dis[adjNode]}});
                }
            }

        }

        if(dis[dst] ==  1e9){
            return -1;
        }
        return dis[dst];
    }
};