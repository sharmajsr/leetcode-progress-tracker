class Solution {
public:
     
    int getLucky(string s2, int k) {
        int  p = 0, n = s2.size();
        string s="";
        for(int i=0;i<n;i++){
            
            s += to_string(s2[i]-'a'+1);
            // cout<<s2[i] << " " <<s2[i]-'a'<<" "<<s<<endl;
        }
        cout<<"-> "<<s<<endl;
        // p=int(st);
        // "12552031545"
        for(int i=0;i<k;i++){
            int temp = 0 ;
            string s1;
            for(int j=0; j < s.size(); j++){
                temp += s[j]-'0'; 
                s1+= to_string(s[j]-'0');
                // cout<<s<<" "<<i<<" "<<s[j]-'0'<<" "<<temp<<endl;
            }
            s = to_string(temp);
            p=temp;
        }
        return p;
    }
};