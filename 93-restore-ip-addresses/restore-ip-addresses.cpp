class Solution {
public:
    bool isStrValid(string s){
        // cout<<"inside is str val "<<s<<endl;
        if(s.size() == 1)   return true;
        if(s[0] == '0') return false;
        int p = stoi(s);
        return p >=0 and p<=255;
    }
    void solve(string s, int idx, vector<string>&ans,string op,int cur){
        if(cur == -1 ){
            if(idx == s.size()){
                string nop = op.substr(0,op.size()-1);
                ans.push_back(nop);
            }
            
            return ;
        }
        
        for(int i = idx; i < s.size()-cur;i++){
            string temp = s.substr(idx,i-idx+1);
            if( temp.size() > 0 and temp.size() <=3 and isStrValid(temp)){
                solve(s,i+1,ans,op+temp+'.',cur-1);
            }
        }

    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() <= 3)    return {};
        vector<string>ans;
        solve(s,0,ans,"",3);
        return ans;
    }
};