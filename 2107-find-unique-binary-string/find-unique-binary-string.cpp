class Solution {
public:
    void solve(int idx,string op,unordered_map<string,int>um,string &ans,int n){
        if(idx == n){
            if(um.find(op) == um.end()){
                ans = op;
            }
            return;
        }
        
        solve(idx+1,op+'0',um,ans,n);
        if(ans != "")   return;
        solve(idx+1,op+'1',um,ans,n);
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int>um;
        for(auto i : nums)  ++um[i];
        string ans;
        solve(0,"",um,ans,nums[0].size());
        return ans;
    }
};