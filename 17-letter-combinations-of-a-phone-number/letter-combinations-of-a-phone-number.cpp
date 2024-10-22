class Solution {
public:
    void solve(string ip,string op,vector<string>&ans,string mappings[]){
        if(ip.size() == 0){
            ans.push_back(op);
            return ;
        }
        int curDigit = ip[0]-'2';
        string curMappedItems = mappings[curDigit];
        ip.erase(ip.begin());
        for(int i=0;i<curMappedItems.size();i++){
            solve(ip,op+curMappedItems[i],ans,mappings);
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0 ) return {};
        string mappings[]={ "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string cur;
        vector<string>ans;
        solve(digits,cur,ans,mappings);
        // for(auto i : ans){
        //     cout<<i<<endl;
        // }
        return ans;
    }
};