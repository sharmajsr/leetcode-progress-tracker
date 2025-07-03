class Solution {
public:
    bool isReachable(int src, int dest, unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        if(src == dest){
            return true;
        }
        visited[src]=true;
        bool isReach = false;
        for(auto it: adj[src]){
            if(!visited[it] and isReachable(it,dest,adj,visited)){
                isReach = true;
            }
        }
        return isReach;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        vector<bool>result(queries.size(),false);
        for(auto i : prerequisites){
            int u = i[0] , v = i[1];
            adj[u].push_back(v);
        }


        for(int i= 0;i<queries.size();i++){
            int u = queries[i][0] , v =  queries[i][1]; 
            vector<bool>visited(numCourses,false);
            result[i] = isReachable(u,v,adj,visited);
        }
        return result;
    }
};