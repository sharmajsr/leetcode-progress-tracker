class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>um;
        int i = 0 , j = 0 , n= s.size() ,maxL = 0;
        while(j < n){
            ++um[s[j]];
            // cout<<um.size()<<" "<<j-i+1<<endl;
            if(um.size() == j-i+1){
                maxL = max(maxL,j-i+1 );
                ++j;
            }else if(um.size()< j-i+1){
                while(um.size() < j-i+1){
                    --um[s[i]];
                    if(um[s[i]] == 0 ){
                        um.erase(s[i]);
                    }
                    ++i;
                }
                ++j;
            }
        }
        return maxL;
    }
};