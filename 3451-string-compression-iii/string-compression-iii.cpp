class Solution {
public:
    string compressedString(string word) {
        string ans;
        unordered_map<string,int>um;
        int n= word.size(),i=0;
        word+=';';
        while(i<n){
            int j = i+1;
            while(j<n and word[i] == word[j]){
                if(j-i == 9){
                    ans += '9';
                    ans += ( word[i]);
                    i=j;
                }
                ++j;
            }
            ans += '0' + (j-i);
            ans += word[i];
            i=j;
        }
        return ans;
    }
};