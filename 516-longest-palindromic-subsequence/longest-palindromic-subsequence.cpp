class Solution {
public:
    vector<vector<int>>dp;
    int findLCS(string s,string t ,int x,int y ){

        if(x == -1 or y == -1 ){
            return 0;
        }
        if(dp[x][y] != -1)  return dp[x][y];
        if(s[x] == t[y]){
            return dp[x][y] = 1+ findLCS(s,t,x-1,y-1);
        }
        else
        return dp[x][y] = max(findLCS(s,t,x-1,y),findLCS(s,t,x,y-1));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size() ;
        dp.resize(s.size()+1,vector<int>(s.size()+1,0));
        string t = s;
        reverse(t.begin(),t.end());
        for(int i=1 ;i <=n; i++){
            for(int j=1;j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        // cout<<s<<" "<<t<<endl;
        // findLCS(s,t,s.size()-1,t.size()-1);
        return dp[s.size()][s.size()];
    }
};