class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size() ,i = 0 ,flag = 0 ;
        string temp;
        while(i<=200){
            char ch = str[0][i];
            for(int j=0 ; j<n ; j++){
                string t = str[j];
                if(i == t.size()){
                    i-=1;
                    flag = 1;
                    break;
                }
                else if(ch != t[i]){
                    flag = 1;
                    break;
                }

            }
            if(flag) break;
            temp += ch;
            ++i;
        }
        return temp;
    }
};