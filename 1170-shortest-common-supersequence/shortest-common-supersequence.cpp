class Solution {
public:
    int solve(string &s1, string &s2,int i ,int j ,vector<vector<int>>&dp ){
        if( i == 0 or j == 0)   return dp[i][j]= 0;
        if(dp[i][j] != -1)  return dp[i][j];
        if(s1[i-1] == s2[j-1])  return dp[i][j]= 1+solve(s1,s2,i-1,j-1,dp);
        return dp[i][j]= max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size() , m = s2.size() ,i,j;
        string temp;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        solve(s1,s2,n,m,dp);
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        i = n ;
        j = m ;
        while( i>0 and j>0){
            if(s1[i-1] == s2[j-1]){
                temp+=s2[j-1];
                --i;
                --j;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                temp += s1[i-1];
                --i;
            }else{
                temp += s2[j-1];
                --j;
            }
        }
        while(i>0){
            temp += s1[i-1];
            --i;
        }
        while(j>0){
            temp += s2[j-1];
            --j;
        }
        reverse(temp.begin(),temp.end());
        return temp;

    }
};