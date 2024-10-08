class Solution {
public:
    int minSwaps(string s) {
        if( s.size() == 0 ) return 0;
        int ans = 0; 
        stack<char>stk;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '['){
                // cout<<s[i]<<endl;
                stk.push(s[i]);
            }
            else if(s[i] == ']'){
                if(!stk.empty()){
                    stk.pop();
                }
                else if(stk.empty()){
                    ++ans;
                }
            }
        }
        return (stk.size() + 1)/2;
    }
};