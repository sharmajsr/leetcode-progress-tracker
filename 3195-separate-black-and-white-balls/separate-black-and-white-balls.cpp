class Solution {
public:
    long long minimumSteps(string s) {
        long long i= 0 , j = s.size()-1;
        long long ans = 0;
        while(i<j){
            if(s[i] == '1'){
                while(j>0 and j>i and s[j] == '1'){
                    --j;
                }
                ans += j-i;
                swap(s[i],s[j]);
            }
            ++i;
        }
        return ans;
    }
};
// i = 0 
// j = 4
//   1 2   
// 0 1 0 1 1
// ans += 4