class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>temp,t2;
        vector<int>adj[2002];
        vector<int>in(n);
        for(auto i : prerequisites){
            ++in[i[0]];
            adj[i[1]].push_back(i[0]);
        }
        queue<int>q;
        for(int i = 0 ;i < n; i++){
            if(in[i] == 0 ){
                q.push(i);
            }
        }

        while(!q.empty()){
            int fr = q.front();q.pop();
            temp.push_back(fr);
            for(auto it : adj[fr]){
                --in[it];
                if( in[it] == 0 ){
                    q.push(it);
                }
            }
        }
        return (temp.size() == n) ? temp : t2 ;
    }
};