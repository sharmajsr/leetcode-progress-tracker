class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i = 0, j=0 , n= s.size() , maxLen = 0;
        for(int i=0 ; i<n ; i++){
            unordered_map<char,int>um;
            for(int j=i ; j<n ; j++){
                ++um[s[j]];
                if(um[s[j]] > 1){
                    break;
                }
                maxLen = max(maxLen , j-i+1);
            }
        }
        // while(j<n){
        //     ++um[s[j]];
        //     if(j-i+1 == um.size()){
        //         if(maxLen < j-i+1){
        //             maxLen = j-i+1;
        //         }
        //         ++j;
        //     }else if(um.size() < j-i+1){
        //         while(j-i+1 != um.size()){
        //             --um[s[i]];
        //             if(um[s[i]] == 0 ){
        //                 um.erase(s[i]);
        //             }
        //             ++i;
        //         }
        //         if(maxLen == j-i+1){
        //             maxLen = j-i+1;
        //         }
        //         ++j;
        //     }
        // }
        return maxLen;
    }
};

// abcabcbb