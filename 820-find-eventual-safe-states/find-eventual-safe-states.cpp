class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[10002];
        vector<int>in(n,0);
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(graph[i].size() > 0){
                for(int j : graph[i]){
                    ++in[i];
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(in[i] == 0  ) {
                q.push(i);
                // cout<<"Pushed into q "<<i<<endl;
            }   
        }
        while(!q.empty()){
            auto top = q.front();
            ans.push_back(top);
            q.pop();
            for(auto i : adj[top]){
                --in[i];
                if(in[i] == 0 ){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};