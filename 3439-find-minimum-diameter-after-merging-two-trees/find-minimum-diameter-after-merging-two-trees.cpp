class Solution {
public:
    int dfs(unordered_map<int,vector<int>>adj,int n){
        vector<int>vis(n+1,0);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        int last ; 
        while(!q.empty()){
            queue<int>qu;
            while(!q.empty()){
                last = q.front();
                q.pop();
                for(auto i : adj[last]) {
                    if(!vis[i]){
                        vis[i]=1;
                        qu.push(i);
                    }
                }
            }
            q=qu;
        }
        // cout<<"last :  "<<last<<endl;
        vector<int>visit(n+1,0);
        visit[last]=1;
        // q.empty();
        q.push(last);
        int hops = 0;
        while(!q.empty()){
            queue<int>qu;
            while(!q.empty()){
                last = q.front();
                q.pop();
                for(auto i : adj[last]) {
                    if(!visit[i]){
                        visit[i]=1;
                        qu.push(i);
                    }
                }
            }
            q=qu;
            ++hops;
        }
        cout<<last<<" "<<hops<<endl;
        return hops-1;
        
    }
    int getSmallestDiameterOfTree(vector<vector<int>> edges){
        int n =edges.size(),minDiameter = 0 ;
        vector<int>vis(n,0);
        vector<int>dis(n,0);
        // vector<int>adj[n];
        unordered_map<int,vector<int>>adj;
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        // for(int i= 0 ;i<n;i++){
        //     if(!vis[i]) dfs(adj,n);
        // }
        // for(int i=0;i<n;i++){
        //     minDiameter = min(minDiameter,dis[i]);
        // }
        return dfs(adj,n);
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int dia1 = getSmallestDiameterOfTree(edges1), dia2 = getSmallestDiameterOfTree(edges2);
        int rad1  = (dia1 +1)/2;
        int rad2  = (dia2 +1)/2;
        int sum = 1 +rad1+rad2;
        // cout<<rad1<<" "<<rad2<<" "<<sum<<endl;
        return max(1+rad1+rad2,max(dia2,dia1));
    }
};