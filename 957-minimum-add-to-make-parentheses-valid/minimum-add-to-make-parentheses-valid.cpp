class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char>stk;
        for(auto i : s){
            if(!stk.empty() and stk.top() =='(' and i ==')'){
                stk.pop();
            }
            else{
                stk.push(i);
            }
        }
        return stk.size();
    }
};