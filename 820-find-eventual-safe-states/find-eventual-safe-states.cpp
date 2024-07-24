class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int>q;
        vector<int>ans;
        vector<int>in(n,0);
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0 ; j < graph[i].size() ; j++ ){
                ++in[i];
                adj[graph[i][j]].push_back(i);
            }
        }

        for(int i=0;i<n;i++){
            if(in[i] == 0 ) q.push(i);
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            ans.push_back(it);
            for(auto j:adj[it]){
                --in[j];
                if(in[j] == 0 ){
                    q.push(j);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};