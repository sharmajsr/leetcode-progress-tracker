class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>in(numCourses,0);
        vector<int>adj[2001];
        vector<int>temp;
        for(int i= 0; i < pre.size(); i++){
            ++in[pre[i][0]];
            adj[pre[i][1]].push_back(pre[i][0]); 
        }
        queue<int>q;
        for(int i= 0 ;i < numCourses; i++){
            if(in[i] == 0 ){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            temp.push_back(top);
            for(auto it : adj[top]){
                --in[it];
                if(in[it] == 0){
                    q.push(it);
                }
            }
        }
        return temp.size() == numCourses ? temp : vector<int>{};
    }
};