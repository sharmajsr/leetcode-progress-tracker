class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>um;
        int i = 0 , j = 0 , n= s.size() ,maxL = 0;
        while(j < n){
            // um[s[j]]=j;
            if(um.find(s[j]) != um.end()){
                if(um[s[j]] >= i){
                    i = um[s[j]] + 1;
                }
            }
            maxL = max(maxL, j-i+1);
            um[s[j]] = j;
            ++j;
        }
        return maxL;
    }
};