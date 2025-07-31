class Solution {
public:
    // unordered_map<pair<int,int>,int>um;
    vector<vector<int>>dp;
    bool solve(string s, int idx,int val){
        if(val < 0 ){
            return false;
        }
        
        if(idx == s.size()){
            return val == 0;
        }
        
        if(dp[idx][val] != -1 ){
            return dp[idx][val];
        }
        if(s[idx] == '('){
            return  dp[idx][val] = solve(s,idx+1,val+1);
        }else if(s[idx] == ')'){
            return  dp[idx][val] = solve(s,idx+1,val-1);
        }else{
            return  dp[idx][val] = solve(s,idx+1,val) or solve(s,idx+1,val+1) or solve(s,idx+1,val-1);
        }
        

    }
    bool checkValidString(string s) {
        // unordered_map<pair<int,int>>um;
        
        dp.resize(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(s,0,0);
    }
};