class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        stack<char>st;
        int n=s.size();
        vector<int>freq(26,0);
        vector<bool>seen(26,0);
        for(auto i :s)  ++freq[i-'a'];
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a'] == true){
                --freq[s[i]-'a'];
                continue;
            }
            while( !st.empty() && st.top() > s[i] && freq[st.top()-'a'] >0 ){
                seen[ st.top()-'a' ] = false;
                st.pop();
            }
            --freq[s[i]-'a'];
            seen[s[i]-'a']=true;
            st.push(s[i]);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};