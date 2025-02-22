class Solution {
public:
    void solve(string op,unordered_map<string,int>um,string &ans,int n){
        int idx = op.size();
        if(idx == n){
            if(um.find(op) == um.end()){
                ans = op;
            }
            return;
        }
        
        solve(op+'0',um,ans,n);
        if(ans != "")   return;
        solve(op+'1',um,ans,n);
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int>um;
        for(auto i : nums)  ++um[i];
        string ans;
        solve("",um,ans,nums[0].size());
        return ans;
    }
};