class Solution {
public:
    bool chkPal(string s ,int i, int j){
        while(i<j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>>&ans, vector<string>path,int idx, string s){
        if(idx == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=idx ; i<s.size();i++){
            string temp = s.substr(idx, i-idx+1);
            bool chkpal = chkPal(s,idx,i);
            if(chkpal){
                path.push_back(temp);
                solve(ans,path,i+1,s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        solve(ans,{},0,s);
        return ans;
    }
};