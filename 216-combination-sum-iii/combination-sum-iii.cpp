class Solution {
public:
    void solve(vector<vector<int>>&res, vector<int>path, int n, int k , int idx){
        if( n==0 ){
            if( k==0){
                res.push_back(path);
                return;
            }
            return;
        }
        if( k == 0 ){
            return;
        }
        for(int i = idx ; i <= 9 ; i++){
            if(n>=i ){
                path.push_back(i);
                solve(res,path,n-i,k-1,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        solve(res,{},n,k,1);
        return res;
    }
};
