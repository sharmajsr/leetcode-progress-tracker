class Solution {
public:
    string minWindow(string s, string t) {
        int ans =1e9;
        int start = -1 ,i = 0,j=0 , m = t.size() , n =s.size() ,cnt = 0;
        unordered_map<int,int>um;
        for(int i= 0; i <t.size(); i++){
            ++um[t[i]];
        } 
        cnt=0;
        while(j<n){
            --um[s[j]];
            if(um[s[j]] >= 0 ){
                cnt+=1;
            }
            if(cnt == t.size()){
                while(cnt== t.size()){
                    if(ans > j-i+1){
                        ans =  j-i+1; 
                        start = i; 
                    }
                    ++um[s[i]];
                    if(um[s[i]] > 0 ){
                        --cnt;
                    } 
                    ++i;
                }
                ++j;

            }else{
               ++j; 
            }
        }
        
        return start == -1? "": s.substr(start,ans);
    }
};

// ABC -> { A:0 , B : 0 , C:1, D : 0 , O: 0, E: 0, N= -1, }
//                   i
//                         j
// A D O B E C O D E B A N C
// cnt = 3
