class Solution {
public:
    vector<int> findOrder(int numC, vector<vector<int>>& prerequisites) {
        vector<int>adj[2002];
        vector<int>v;
        vector<int>in(numC,0);
        vector<int>toposort;
        queue<int>q;
        for(auto i : prerequisites){
            // if(i[1] == i[0])    return false;
            adj[i[1]].push_back(i[0]);
            ++in[i[0]];
        }
        for(int i=0;i<numC;i++){
            if(in[i] == 0 ) q.push(i);
        }
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            toposort.push_back(cur);
            
            for(auto j : adj[cur]){
                --in[j];
                if(in[j] == 0 ){
                    q.push(j);
                }
            }
        }
        return  toposort.size() == numC ? toposort : v;
    }
};