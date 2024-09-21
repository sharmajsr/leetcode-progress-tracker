class Solution {
public:
    vector<int>ans;
    void dfs(int curr,int n){
        if(curr>n) return ;
        ans.push_back(curr);
        for(int i=0;i<=9;i++){
            int x = curr * 10 + i;
            if(x > n)   return;
            dfs(x,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i= 1 ;i<=9;i++){
            dfs(i,n);
        }
        return ans;
    }
};