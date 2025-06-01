class Solution {
private:
    void dfs(vector<int>adj[],vector<int>&vis,vector<int>&res,int cur){
        vis[cur] =1;
        res.push_back(cur);
        for(auto it : adj[cur]){
            if(!vis[it]){
                dfs(adj,vis,res,it);
            }
        }
        
    }
public:
    int findCircleNum(vector<vector<int>>& ad) {
        int n = ad.size(),cnt= 0 ;
        // Code here
        vector<int>res;
        vector<int>adj[201];
        vector<int>vis(n,0);
        for(int i= 0 ;i < n; i++){
            for(int j=0 ; j <n; j++){
                if(i!=j && ad[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ++cnt;
                dfs(adj,vis,res,i);
            }
        }
        return cnt;
    }
};