class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>um;
        string ans;
        int n = s.size();
        if(n&1) n+=1;
        for(auto i : s){
            ++um[i];
        }
        priority_queue<pair<int,char>>maxH;
        for(auto i : um){
            // cout<<i.first<< " "<<i.second<<" "<<n<<endl;
            if(i.second > n/2)  return "";
            maxH.push({i.second,i.first});
        }
        while(!maxH.empty()){
            auto e1 = maxH.top();maxH.pop();
            ans += e1.second;
            if(maxH.empty()) break;
            pair<char,int>e2;
            // if(maxH.size() > 0 )
            e2 = maxH.top();maxH.pop();

            
            // if(maxH.size() > 0 )
            ans += e2.second;
            
            if(e1.first-1 > 0)  maxH.push({e1.first-1,e1.second});
            // if(maxH.size() > 0 )
            if(e2.first-1 > 0)  maxH.push({e2.first-1,e2.second});
            // cout<<maxH.size()<<" "<<ans<<endl;
            
        }
        return ans ;
    }
};