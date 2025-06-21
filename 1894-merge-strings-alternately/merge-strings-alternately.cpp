class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i  =0 , j = 0 , n = word1.size() ,m = word2.size() ;
        string temp;
        while( i < n and j < m ){
            temp += word1[i++] ;
            temp += word2[j++];
        }
        // cout<<temp<<endl;
        while(i < n){
            temp += word1[i++];
        }
        while(  j < m ){
            temp += word2[j++];
        }
        return temp;
    }
};