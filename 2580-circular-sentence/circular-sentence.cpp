class Solution {
public:
    bool isCircularSentence(string s) {
        int n= s.size(),start = 0 ;
        // vector<string>str;
        if(s[0] != s[s.size()-1])   return false;
        for(int i= 0;i<n;i++){
            if(s[i] == ' '){
               if(s[i-1] != s[i+1]) return false;
            }
        }
        // str.push_back(s.substr(start,n-start));
        
        return true;
        
    }
};