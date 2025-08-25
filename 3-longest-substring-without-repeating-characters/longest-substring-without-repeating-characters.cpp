class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>um;
        int n = s.size() ,ans= 0 ;
        int i = 0, j = 0;
        while(j < n ){
            ++um[s[j]];
            if(um.size() == j-i+1){
                ans = max(ans, j-i+1);
                ++j;
            }else if( j-i+1 > um.size()){
                while(j-i+1 != um.size()){
                    --um[s[i]];
                    if(um[s[i]] == 0){
                        um.erase(s[i]);
                    }
                    ++i;
                }
                ++j;
            }
        }
        return ans;
    }
};