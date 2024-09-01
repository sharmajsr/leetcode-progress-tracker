class Solution {
public:
    long long check(char c,string s){
        long long int n = s.size();
        long long int cnt = 0 ,res = 0;
        for(int i=0;i<n;i++){
            if(s[i] == c){
                res+= (cnt *(cnt+1)) /2;
                cnt=0;
            }
            else ++cnt;
        }
        res+= (cnt *(cnt+1)) /2;
        long long  totalSubstrings ;
        totalSubstrings = (n*(n+1))/2 ;
        return totalSubstrings - res;
    }
    long long appealSum(string s) {
        long long ans = 0 ;
        for(char c ='a' ; c<='z' ; c++){
            ans += check(c,s);
        }
        return ans;
    }
};