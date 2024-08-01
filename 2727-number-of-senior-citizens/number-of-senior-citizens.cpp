class Solution {
public:
    int covertToInt(string s){
        int ans= 0;
        for(auto i : s){
            ans = ans * 10 + ( i-'0');
        }
        return ans;
    }
    int countSeniors(vector<string>& details) {
        int ans = 0 ;
        for(auto i: details){
            int f =  covertToInt(i.substr(11,2));
            if (f>60)   ans++;
        }
        return ans;
    }
};