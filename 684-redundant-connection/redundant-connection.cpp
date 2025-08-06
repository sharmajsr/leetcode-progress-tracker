class DS{
    vector<int>parent, size;
    public:
        DS(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i= 0; i <n; i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        int fUP(int node){
            if(parent[node] == node)    return node;
            return parent[node] = fUP(parent[node]);
        }

        void unionBySize(int u , int v){
            int ult_u = fUP(u);
            int ult_v = fUP(v);
            if(ult_u == ult_v){
                return;
            }
            if(size[ult_u] > size[ult_v]){
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }else{
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
        }
};
class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DS ds(n);
        vector<int>ans;
        for(auto edge: edges){
            
            int u = edge[0], v =edge[1] , p1, p2;
            p1 = ds.fUP(edge[0]);
            p2 = ds.fUP(edge[1]);
            // cout<<u<<" "<<v<<" "<<p1<<" "<<p2<<endl;
            if( p1 == p2) {
                ans = edge;
            }else{
                ds.unionBySize(edge[0],edge[1]);
            }
        }
        return ans;
    }
};