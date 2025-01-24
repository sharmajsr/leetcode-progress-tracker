class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>in(n+1,0);
        vector<int>adj[10001];
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<graph.size();i++){
            // int v0 = pai[0];
            // int v1 = pai[1];
            // adj[v1].push_back(v0);
            
            for(auto k : graph[i]){
                adj[k].push_back(i);
                ++in[i];
            }
            if(graph[i].size() == 0){
                q.push(i);
                
                cout<<"Terminal nodes : "<<i<<endl;
            }
        }
        
        // for(int i=0 ; i <= n ; i++){
        //     if(in[i] == 0 ){
        //         q.push(i);
        //     }
        // }
        while(!q.empty()){
            auto top = q.front();
            ans.push_back(top);
            q.pop();
            for(auto adja : adj[top]){
                --in[adja];
                // cout<<top<<" "<<in[adja]<<endl;
                if(in[adja] == 0 ){
                    q.push(adja);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};