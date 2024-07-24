class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>in(n,0);
        vector<int>ans;
        vector<int>adj[n];
        queue<int>q;
        for(auto i : pre){
            adj[i[1]].push_back(i[0]);
            ++in[i[0]];
        }
        for(int i=0;i<n;i++){
            if(in[i] == 0 ){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            ans.push_back(it);
            for(auto j : adj[it]){
                --in[j];
                if( in[j] == 0 ){
                    q.push(j);
                }
            }
        }
        return ans.size() == n;
    }
};