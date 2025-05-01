class Solution {
public:
    void solve(string s,unordered_map<string,int>&um,int idx,vector<string>&ans,string cur){
        if(idx == s.size()){
            cur.erase(cur.begin()+cur.size()-1);
            ans.push_back(cur);
            return;
        }
        for(int i = idx ; i < s.size() ; i++){
            string temp = s.substr(idx,i-idx+1);
            // cout<<idx<<" "<<i<<" "<<temp<<endl;
            if(um.find(temp) != um.end() ){
                solve(s,um,idx+temp.size(),ans,cur+temp+" ");
            }   
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>um;
        for(auto i : wordDict){
            ++um[i];
        }
        vector<string>ans;
        solve(s,um,0,ans,"");
        return ans;
    }
};