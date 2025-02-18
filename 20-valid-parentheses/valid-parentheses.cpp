class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i : s){
            if( i == '(' or i == '{' or  i=='['){
                st.push(i);
            }
            else if( i == '}' and !st.empty() and st.top() == '{' ){
                st.pop();
            }
            else if( i == ')' and !st.empty() and st.top() == '(' ){
                st.pop();
            }
            else if( i == ']' and !st.empty() and st.top() == '[' ){
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        return st.size() == 0 ;
    }
};