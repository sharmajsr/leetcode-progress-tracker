class Solution {
public:
    string longestPalindrome(string s) {
        // https://www.youtube.com/watch?v=fxwvVnBMN6I
        int n = s.size();
        int dp[n+1][n+1];
        int start = 0 ;
        int maxlen=1;
        memset(dp,0,sizeof(dp));
        for(int diff = 0 ;diff <n ; diff++){
            for(int i=0 , j = i +diff ; j < n ; i++,j++){
                if(i == j) dp[i][j] =1;
                else if(diff == 1 and s[i]==s[j])   dp[i][j] = 2;
                else{
                    if(s[i] == s[j] and dp[i+1][j-1]){
                        dp[i][j] = dp[i+1][j-1]+2;
                    }
                } 

                if(dp[i][j] > 0 and j-i+1 > maxlen ){
                    start =i;
                    maxlen = max(maxlen, j-i+1);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        return s.substr(start,maxlen);
    }
};