class Solution {
public:
    bool isCircularSentence(string s) {
        int n= s.size(),start = 0 ;
        vector<string>str;
        if(s[0] != s[s.size()-1])   return false;
        for(int i= 0;i<n;i++){
            if(s[i] == ' '){
                str.push_back(s.substr(start,i-start));
                start = i+1;
            }
        }
        str.push_back(s.substr(start,n-start));
        for(int i= 1 ;i <str.size() ; i++){
            string curWord = str[i];
            string prevWord = str[i-1];
            // cout<<curWord<<" "<<prevWord<<endl;
            if(curWord[0] != prevWord[prevWord.size()-1]){
                return false;
            }
        }
        return true;
        
    }
};