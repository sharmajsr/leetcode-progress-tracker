class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        s +=" ";
        int n=s.size(),start=0,m =searchWord.size(),wordCount = 0 ;
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                ++wordCount;
                int len = i - start + 1;
                if( len >= m ){
                    int j=0;
                    bool isDifferent =false;
                    for(int k=start ; k<start+len and k<start+m; k++){
                        if(searchWord[j++] != s[k]){
                            isDifferent = true;
                        }
                    }
                    if(!isDifferent){
                        return wordCount;
                    }
                }
                start = i+1;
            }
        }
        return -1;
    }
};