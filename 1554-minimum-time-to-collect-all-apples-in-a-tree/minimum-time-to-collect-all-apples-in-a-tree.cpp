class Solution {
public:
    int solve(vector<int>adj[],vector<int>&vis,vector<bool>&hasApple,int cur,int parent){
        vis[cur]=1;
        int ans = 0; 
        for(auto i : adj[cur]){
            if(i == parent) continue;
            ans += solve(adj,vis,hasApple,i,cur);
        }
        if((cur!=0 and hasApple[cur] == true ) or (cur!=0 and ans>0))   ans += 2;
        
        return ans;
    }   
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int>adj[n];
        vector<int>vis(n,-1);
        for(auto i : edges){
            int a = i[0];
            int b = i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans =0 ; 
        return solve(adj,vis,hasApple,0,-1);
        
    }
};