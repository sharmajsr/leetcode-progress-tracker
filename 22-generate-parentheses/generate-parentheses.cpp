class Solution {
public:
    void solve(int posn,int negn,string curr,vector<string>&output){
        if(posn == 0 and negn == 0 ){
            output.push_back(curr);
            return;
        }
        if(posn>0) solve(posn-1,negn+1,curr+"(",output);
        if(negn > 0 ) solve(posn,negn-1,curr+")",output);
    }
    vector<string> generateParenthesis(int n) {
        int posn = n ;
        int negn = 0 ;
        vector<string>ans;
        solve(posn,negn,"",ans);
        return ans;

    }
};