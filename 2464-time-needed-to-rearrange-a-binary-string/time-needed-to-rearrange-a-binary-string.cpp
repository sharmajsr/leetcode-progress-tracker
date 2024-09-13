class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int ans = 0 ;
        int n=s.size();
        while(true){
            string s2 = s;
            bool flag = true;
            for(int i=1;i<n;i++){
                if(s[i] == '1' and s[i-1] == '0'){
                    s2[i] ='0';
                    s2[i-1] = '1';
                    flag = false;
                }
            }
            if(flag)    break;
            s=s2;
            // cout<<ans<<" "<<s<<endl;
            ++ans;
        }
        return ans;
    }
};

// 0110101 - > 0111001
// 1011010
// 1101100
// 1110100
// 1111000