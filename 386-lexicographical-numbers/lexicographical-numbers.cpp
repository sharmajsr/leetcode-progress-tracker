class Solution {
public:
    void dfs(int cur, int n,vector<int>&ans){
        if(cur > n)   return;
        for(int i=0;i<=9;i++){
            int temp = cur * 10 + i;
            if(temp == 0)   continue;
            if(temp > n)    return;
            ans.push_back(temp);
            dfs(temp,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        // unordered_map<char,vector<string>>um;
        // for(int i=1 ; i <=n; i++){
        //     string temp = to_string(i);
        //     um[temp[0]].push_back(temp);
        // }
        // for(int i=1;i<=9;i++){
        //     // cout<<i+'0'<<endl;
        //     vector<string>temp = um[i+'0'];
        //     sort(temp.begin(),temp.end());
        //     for(auto j: temp){
        //         ans.push_back(stoi(j));
        //     }
        // }
        dfs(0,n,ans);
        return ans;
        
    }
};