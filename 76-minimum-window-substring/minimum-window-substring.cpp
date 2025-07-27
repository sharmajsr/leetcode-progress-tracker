class Solution {
public:
    bool CheckAllElementsArePresent(unordered_map<char,int>&text_map, unordered_map<char,int>&pattern_map){
        for(auto i : pattern_map){
            if( text_map.find(i.first) == text_map.end()){
                return false;
            }
            if(i.second > text_map[i.first]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int start =0 , pattern_map_size = 0, minLen = INT_MAX ;
        unordered_map<char,int>um_text;
        
        unordered_map<char,int>um_pattern;
        for(auto i : t) ++um_pattern[i];
        pattern_map_size = um_pattern.size();
        int i = 0 , j= 0, n =s.size();
        while( j < n ){
            ++um_text[s[j]];
            if(um_text.size() < pattern_map_size){
                ++j;
            }else{
                bool checkAllElementsArePresent = CheckAllElementsArePresent(um_text, um_pattern);
                if(!checkAllElementsArePresent){
                    ++j;
                }else{
                    if(minLen > j-i+1 ){
                        minLen = j-i+1 ;
                        start = i;
                    }
                    --um_text[s[i]];
                    if(um_text[s[i]] == 0){
                        um_text.erase(s[i]);
                    }
                    ++i;
                    while(CheckAllElementsArePresent(um_text, um_pattern)){
                        if(minLen > j-i+1 ){
                            minLen = j-i+1 ;
                            start = i;
                        }
                        --um_text[s[i]];
                        if(um_text[s[i]] == 0){
                            um_text.erase(s[i]);
                        }
                        ++i;
                    }
                    ++j;
                }
                
            }

            
        }
        if(minLen == INT_MAX)   minLen =0;
        return s.substr(start,minLen);
        
    }
};
// A : 1 , B = 1 , C = 1 -> 3
// ij
// ADOBECODEBANC 
// size_text = 4 
// i = 0 
// j = 1
// A : 1 , D : 1 ,O : 1 , B : 1
// 
