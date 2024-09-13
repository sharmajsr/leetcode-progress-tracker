class Solution {
public:
    string getString(int p){
        string result;
        while(p >0 ){
            int rem = p%10;
            p/=10;
            result += rem+'0';
        }
        return result;
    }
    int getLucky(string s2, int k) {
        int  p = 0, n = s2.size();
        string s="";
        for(int i=0;i<n;i++){
            
            s += getString(s2[i]-'a'+1);
            
        }
        
        for(int i=0;i<k;i++){
            int temp = 0 ;
            string s1;
            for(int j=0; j < s.size(); j++){
                temp += s[j]-'0'; 
                s1+= to_string(s[j]-'0');
                
            }
            s = getString(temp);
            p=temp;
        }
        return p;
    }
};