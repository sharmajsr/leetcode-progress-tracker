class Solution {
public:
    bool isDivisor(string s,string p){
        int k = p.size();
        for(int i= 0; i< s.size() ; i+=k){
            if(s.substr(i,k) != p ){
                return false;
            }
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size() , m = str2.size() ,i = 0, j= 0,k=1;
        string temp;
        while(i<n and j<m){
            string t = str2.substr(0,k);
            if( isDivisor(str1,t) and isDivisor(str2,t) ){
                // cout<<"found div at k : " <<k<<" "<<str1.substr(0,k)<<" "<<str2.substr(0,k)<<endl;
                temp = str1.substr(0,k);
            }
            ++k;
            ++i;
            ++j;
        }
        return temp;
    }
};