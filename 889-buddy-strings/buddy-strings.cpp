class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        bool swapped = false , c1 = true ,  c2 = true;
        int i= 1 , j= s.size();
        // edge case :  when both strings are same;
        unordered_map<char,int>um1,um2;
        for(auto i : s) ++um1[i];
        for(auto i : goal) ++um2[i];
        if(s == goal){
            bool np =false;
            for(auto i : um1){
                if(i.second > 1){
                    np = true;
                }
            }
            return np;
        }

        // normal cases : when both strings are different
        i= 0 , j= s.size();
        while( i < j ){
            if(goal[i] != s[i]){
                while(j>i and goal[j] == s[j]){
                       --j; 
                }
                swap(s[i],s[j]);
                return s == goal;
            }else{
                ++i;
            }
        }
        return false;
    }
};