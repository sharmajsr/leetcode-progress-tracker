class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        priority_queue<pair<int,char>>maxH;
        unordered_map<char,int>um;
        for(auto i : s){
            ++um[i];
        }
        for(auto i : um){
            maxH.push({i.second,i.first});
        }
        while(!maxH.empty()){

            auto fir = maxH.top(); maxH.pop();
            ans += fir.second;
            if(maxH.empty() and fir.first > 1)   return "";

            pair<int,char> sec;
            if(!maxH.empty()){
                sec = maxH.top();maxH.pop();
                ans += sec.second;
            }

            if(fir.first-1>0)   maxH.push({fir.first-1,fir.second});
            if(sec.first-1>0)   maxH.push({sec.first-1,sec.second});
        }
        return ans;
    }
};
// aab , a=1 
// 