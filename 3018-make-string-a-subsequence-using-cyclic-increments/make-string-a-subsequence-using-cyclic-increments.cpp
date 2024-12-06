class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if( str2.size() > str1.size() ) return false;
        int i=0, j =0,n= str1.size() , m = str2.size();
        while( i< n and j<m){
            char nextCharacter = char((str1[i]-'a' + 1)%26)+'a';
            // cout<<str1[i]<<" "<<nextCharacter<<endl;
            if( str1[i] == str2[j] or nextCharacter == str2[j] ) {
                ++i;
                ++j;
            }else{
                ++i;
            }
        }
        return j==m;
    }
};