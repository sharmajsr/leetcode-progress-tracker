class Solution {
public:
    void solve(string digits,vector<string>&op,string curr){
        if(digits.size() == 0 ){
            op.push_back(curr);
            return;
        }
        string letters[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int currDigit = digits[0]-'0';
        digits.erase(digits.begin());
        string currDigitLetters = letters[currDigit];
        for(auto i : currDigitLetters){
            solve(digits,op,curr+i);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")    return {};
        vector<string>ans;
        solve(digits,ans,"");
        return ans;
    }
};