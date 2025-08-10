class Solution {
public:
    bool checkPal(string s, int i ,int j){
        while(i<=j){
            if( s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    void solve(string s,vector<string>path,vector<vector<string>>&res,int start){
        if(start == s.size()){
            res.push_back(path);
            return ;
        }

        for(int i = start ; i < s.size(); i++){
            string temp = s.substr(start,i-start+1);
            bool pal_res = checkPal(s,start,i);
            if(checkPal(s,start,i)){
                path.push_back(temp);
                solve(s,path,res,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        solve(s,res,ans,0);
        return ans;
    }
};