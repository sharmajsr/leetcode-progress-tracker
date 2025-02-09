class Solution {
public:
    bool checkPalindrome(string s){
        string t = s;
        reverse(t.begin(),t.end());
        return s == t;
    }
    void solve(string s,int idx, vector<string>op,vector<vector<string>> &ans){
        if( idx == s.size()){
            ans.push_back(op);
            return;
        }
        for(int i = idx; i < s.size() ; i++){
            string temp = s.substr(idx,i-idx+1);
            if(checkPalindrome(temp)){
                op.push_back(temp);
                solve(s,i+1,op,ans);
                op.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>op;
        solve(s,0,op,ans);
        return ans;
    }
};