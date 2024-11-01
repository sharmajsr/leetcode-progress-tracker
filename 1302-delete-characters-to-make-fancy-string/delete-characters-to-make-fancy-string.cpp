class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() <= 2 )  return s;
        int n=s.size();
        string ans ;
        ans = s.substr(0,2);
        for(int i=2;i<n;i++){
            if(s[i] == s[i-1] and s[i] ==s[i-2])
                continue;
            ans +=s[i];
        }
        return ans;
    }
};