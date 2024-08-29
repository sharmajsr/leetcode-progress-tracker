class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // int n = edges.size();
        vector<int>vec(n,0);
        int cnt = 0,ans = 0;
        for(int i= 0;i<edges.size();i++){
            ++vec[edges[i][1]];
        }
        for(int i=0;i<n;i++){
            if(vec[i] == 0 ){
                ++cnt;
                ans= i ;
            }
        }
        return cnt >1 ? -1 : ans;
    }
};