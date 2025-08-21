class Solution {
public:
    void printEl(vector<int>v){
        for(auto i : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void solve(vector<vector<int>>&ans , vector<int>path, int k, int n,int idx){
        cout<<n<<endl;
        if( n == 0){
            // cout<<"Printing path : " ;
            // printEl(path);
            if(k == 0) {
                ans.push_back(path);
                return;
            }
            return ;
        }
        if(k == 0 ){
            return;
        }
        for(int i= idx ; i<=9 ; i++){
            if(n >= i){
                path.push_back(i);
                solve(ans, path, k-1, n-i , i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        solve(ans,{},k,n,1);
        return ans;
    }
};