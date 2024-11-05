class Solution {
public:
    int minChanges(string s) {
        int a = 0 ;
        for(int i=0;i<s.size();i+=2){
            if(s[i] != s[i+1])  ++a;
        }
        return a;
        
    }
};