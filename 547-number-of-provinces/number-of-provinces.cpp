class Solution {
public:
    void dfs(int curNode, vector<int>adj[],vector<int>&vis){
        vis[curNode]=1;
        for(auto j : adj[curNode]){
            if(!vis[j]){
                cout<<curNode<<" "<<j<<endl;
                dfs(j,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ,ans = 0 ;
        vector<int>vis(n+1,0);
        vector<int>adj[201];
        for(int i=0;i<n;i++){
            for(int j= 0 ;j <n; j++){
                if( i!= j and isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     cout<<i<<" : ";
        //     for(auto j : adj[i]){
        //         cout<<j<<",";
        //     }
        //     cout<<endl;
        // }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                ++ans;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};