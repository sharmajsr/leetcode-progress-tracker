class Solution {
public:
    bool solve(string s, unordered_map<string,int>&um, int idx,vector<int>&dp){
        if(idx == s.size()) return true;
        if(idx > s.size() ) return false;

        if(dp[idx] != -1)   return dp[idx];
        
        for(int i= idx;i < s.size(); i++){
            string temp = s.substr(idx,i-idx+1);
            if(um.find(temp) != um.end() and solve(s,um,i+1,dp)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>um;
        vector<int>v(s.size(),-1);
        for(auto i : wordDict) ++um[i];
        return solve(s,um,0,v);
    }
};