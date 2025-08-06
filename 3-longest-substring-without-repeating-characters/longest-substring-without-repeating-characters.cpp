class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0 ;
        int i = 0, j=0 , n =s.size();
        unordered_map<int,int>um;
        while(j < n ){
            ++um[s[j]];
            if(j-i+1 ==um.size() ){
                maxLen = max(maxLen, j-i+1);
                ++j;
            }else if(j-i+1 > um.size()){
                while(um.size() != j-i+1){
                    --um[s[i]];
                    if(um[s[i]] == 0 ){
                        um.erase(s[i]);
                    }
                    ++i;
                }
                maxLen = max(maxLen, j-i+1);
                ++j;
            }
        }
        return maxLen;
    }
};