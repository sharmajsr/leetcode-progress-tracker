// using the odd and even method for counting palindrom,  take and idx and go out and icrease count
// 
class Solution {
public:
    int solve(string s, int i, int j){
        int cnt = 0 ;
        while(i>=0 and j <s.size() and s[i]==s[j]){
            ++cnt;
            --i;
            ++j;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int ans = 0 ;
        for(int i = 0 ;i < s.size();i++){
            ans += solve(s,i,i);
            ans += solve(s,i,i+1);
        }
        return ans;
    }
};