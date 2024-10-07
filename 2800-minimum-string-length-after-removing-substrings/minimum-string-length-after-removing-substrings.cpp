class Solution {
public:
    int minLength(string s) {
        bool isPresent = true;
        while(true){
            isPresent = false;
            int n = s.size();
            
            for(int i=0;i<n-1;i++){
                if(s[i] == 'A' and s[i+1] == 'B'){
                    isPresent = true;
                    s.erase(s.begin()+i,s.begin()+i+2);
                }
                else if(s[i] == 'C' and s[i+1] == 'D'){
                    isPresent = true;
                    s.erase(s.begin()+i,s.begin()+i+2);
                }
            }
            // cout<<s<<endl;
            if(!isPresent)  break;
        }
        return s.size();
    }
};