class Solution {
public:
// int solve(string s,int idx1,int idx2){
//     if(idx1 > idx2){
//         return 0;
//     }
//     if(idx1 == idx2)    return 1;
    
// }
    bool checkPalindrome(string s, int i , int j){
        while( i < j ){
            if(s[i] != s[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    int countSubstrings(string s) {
        int ans = 0 , n = s.size();
        for(int i= 0 ; i <n; i++){
            for(int j = i ; j <n; j++){
                bool ck = checkPalindrome(s,i,j);
                // cout<<s.substr(i,j-i+1)<< " " <<ck<<endl;
                if(ck){
                    ++ans;
                }
            }
        }
        return ans;
    }
};