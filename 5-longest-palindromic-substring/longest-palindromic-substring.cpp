class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n+1][n+1];
        int start = 0 ;
        int maxlen=1;
        memset(dp,false,sizeof(dp));
        // for(int i=0;i<=n;i++){
        //     dp[i][i] =  1;
        // }
        // for(int k= 1 ;k<n;k++){
        for(int diff = 0 ; diff<n ; diff++){
            for(int i=0,j=i+diff ; j<n ; i++,j++){
                // int j = i+k;
                if( i==j) dp[i][j] = 1;
                else if (diff == 1){
                    dp[i][j]= s[i] == s[j] ? 2 : 0;
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = dp[i+1][j-1] +2;
                    }
                    // else{
                    //     dp[i][j] = dp[i+1][j-1] ;
                    // }
                }
                if(dp[i][j] > maxlen){
                    maxlen = dp[i][j];
                    start =i;
                }

            }
        }
        return s.substr(start,maxlen);
    }
};