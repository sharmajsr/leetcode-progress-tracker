class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int start = 0 ;
        for(int i=0;i<spaces.size();i++){
            ans += s.substr(start,spaces[i]-start);
            ans +=" ";
            start = spaces[i];
        }
        ans+= s.substr(start,s.size()-start);
        return ans;
    }
};