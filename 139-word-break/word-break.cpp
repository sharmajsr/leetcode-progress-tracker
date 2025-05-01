class Solution {
public:
bool solve(string s,unordered_map<string,int>& wordDict,int idx,vector<int>&v){
    if(idx == s.size()) return true;
    else if(idx > s.size()) return false;
    if(v[idx] != -1)    return v[idx];
    for(int i = idx; i < s.size() ; i++ ){
        string temp = s.substr(idx,i-idx+1);
        // cout<<idx<<" "<<temp<<" "<<i<<endl;
        if(wordDict.find(temp) != wordDict.end() and solve(s,wordDict,i+1,v)){
            // cout<<
            return v[idx] = true;
        }
    }
    return v[idx]= false;

}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>um;
        // sort(wordDict.begin(),wordDict.end(),greater<string>());
        vector<int>v(s.size(),-1);
        for(auto i : wordDict){
            ++um[i];
        }
        return solve(s,um,0,v);

    }
};