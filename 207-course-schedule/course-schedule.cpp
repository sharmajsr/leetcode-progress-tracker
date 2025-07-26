class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[2002];
        vector<int>in(numCourses,0);
        vector<int>ans;
        for(auto i :prerequisites ){
            int v = i[0];
            int u = i[1];
            adj[u].push_back(v);
            ++in[v];
        }
        queue<int>q;
        for(int i = 0 ;i <numCourses;i++){
            if(in[i] == 0 ){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto fr = q.front();q.pop();
            ans.push_back(fr);
            for(auto it : adj[fr]){
                --in[it];
                if(in[it] == 0 ){
                    q.push(it);
                }
            }
        }
        return ans.size() == numCourses;
    }
};