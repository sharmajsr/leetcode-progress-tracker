class Solution {
public:
    string reformatDate(string date) {
        int n = date.size(),start = 0;
        unordered_map<string,string>mp;
        mp["Jan"]="01";mp["Feb"]="02";mp["Mar"]="03";mp["Apr"]="04";mp["May"]="05";mp["Jun"]="06";
        mp["Jul"]="07";mp["Aug"]="08";mp["Sep"]="09";mp["Oct"]="10";mp["Nov"]="11";mp["Dec"]="12";
        vector<string>v;
        date+=" ";
        for(int i=0;i<=n;i++){
            if(date[i] == ' '){
                v.push_back(date.substr(start,i-start));
                start = i+1;
            }
        }
        for(auto i : v) cout<<i<<" ";
        // cout<<endl;
        string day = "";
        for(auto i : v[0]){
            if(i >= '0' and i<='9') day += i;
        }
        if(day.size() == 1){
            day = '0'+day;
        }
        string ans = v[2]+"-"+mp[v[1]]+"-"+day;
        return ans;
    }
};