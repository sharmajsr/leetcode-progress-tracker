class Solution {
public:
    string solve(string s ,int n){
        if(n<=0) return s;

        string p="";
        for(auto i : s){
            p+= (i+1);
        }
        return solve(s+p,n-1);
    }
    char kthCharacter(int k) {
        string s ;
        s = solve("a",9);
        cout<<s<<endl;
        return s[k-1];
    }
};