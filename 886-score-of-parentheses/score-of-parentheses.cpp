class Solution {
public:
    int scoreOfParentheses(string s) {
        if(s.size() == 0 )  return 0;
        int depth = 0 , n = s.size() ,ans= 0 ;
        
        for(int i=0;i<n;i++){
            if(s[i] == '(') depth +=1 ;
            else if(s[i] == ')'){
                if(s[i-1] != '(')   depth-=1;
                else{
                    ans += pow(2,depth-1);
                    --depth;
                }    
            }
        }
        return ans;
    }
};