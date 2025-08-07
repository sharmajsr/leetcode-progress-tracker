class Solution {
public:
    string minWindow(string s, string t) {
        int ans =1e9;
        int start = -1 ,i = 0,j=0 , m = t.size() , n =s.size() ,cnt = 0;
        unordered_map<int,int>um;
        for(int i= 0; i <t.size(); i++){
            ++um[t[i]];
        } 
        i=0;
        while(j<n ){
            if( um[s[j]] > 0 ) cnt += 1;
            --um[s[j]];
            while( cnt == m ){
                if(j-i+1 < ans){
                    ans= j-i+1;
                    start = i;
                }
                um[ s[i] ]++;
                if(um[s[i]] > 0){
                    cnt -=1;
                }
                ++i;
            }
            ++j;
        }
        return start == -1? "": s.substr(start,ans);
        

    }
};