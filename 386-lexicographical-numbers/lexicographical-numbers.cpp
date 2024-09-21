class Solution {
public:
    static bool comp(const string &a,const string &b){
        return a+b > b+a;
    }
    int firstChar(int i){
        while(i>9)  i/=10;
        return i;
    }
    // 1123
    int convertStringToNum(string s){
        int ans = 0;
        for(auto i : s){
            ans = ans*10 + i-'0';
        }
        return ans;
    }
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
        // vector<int>ans;
        vector<string>f;

        vector<string>numbers[10];
        for(int i= 1 ;i<=9;i++){
            dfs(i,n);
        }
        return ans;
    }
};