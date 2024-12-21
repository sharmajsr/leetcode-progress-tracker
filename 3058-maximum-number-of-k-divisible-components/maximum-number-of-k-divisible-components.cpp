class Solution {
public:
int dfs(vector<vector<int>>& adj,vector<int>& values,int& k,int& count,int curr,int parent=-1){
        long long sum=values[curr];
        for(int nbr: adj[curr]){
            if(nbr!=parent)
                sum += dfs(adj,values,k,count,nbr,curr);
        }
        sum %= k;
        if(sum==0)  count++;
        
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count=0;
        dfs(adj,values,k,count,0);
        return count;
    }
};