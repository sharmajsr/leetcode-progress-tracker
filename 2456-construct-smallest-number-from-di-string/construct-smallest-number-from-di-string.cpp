class Solution {
public:
    string smallestNumber(string pattern) {
    
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