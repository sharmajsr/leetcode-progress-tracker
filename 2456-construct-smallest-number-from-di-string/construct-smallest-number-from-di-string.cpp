class Solution {
public:
    string solve(int n,int &cur,string op,string pattern){
        if(cur == n+1){
            return op;
        }
        
        if(pattern[cur-1] == 'I') return to_string(cur+1) + solve(n,cur,op,pattern);
        cur+=1;
        return solve(n,cur,op,pattern) + to_string(cur+1);
    }
    string smallestNumber(string pattern) {
        // int cur =0;
        // return solve(pattern.size(),cur,"",pattern);
        int n = pattern.size();
        string ans;
        for(int i=0;i<=n;i++){
            ans += to_string(i+1);
        }
        for(int i=0 ; i<n ; i++){
            int j=i;
            while(j<n and pattern[j] == 'D'){
                ++j;
            }
            reverse(ans.begin()+i,ans.begin()+j+1);
            if(i !=j ) i= j-1;
        }
        return ans;
    }

};