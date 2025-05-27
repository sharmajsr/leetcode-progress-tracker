class Solution {
public:
    void solve(string digits,vector<string>&ans,int idx,string cur){
        if(idx == digits.size()){
            ans.push_back(cur);
            return;
        }
        string nums[]= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int dig = digits[idx]-'0';
        
        string temp = nums[dig];
        // cout<<idx<<" "<<digits.size()<<" "<<cur<<" "<<dig<<" "<<temp<<endl;
        for(int i= 0 ;i <temp.size();i++){
            solve(digits,ans,idx+1,cur+temp[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string>ans;
        solve(digits,ans,0,"");
        return ans;
    }
};