class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>um;
        string temp;
        for(auto i : s){
            ++um[i];
        }
        priority_queue<pair<int,char>>pq;
        for(auto i : um){
            pq.push({i.second,i.first});
        }
        while(!pq.empty()){
            cout<<"size : "<<pq.size()<<endl;
            if(pq.size() == 1 and pq.top().first > 1) return "";
            auto firs = pq.top(); pq.pop();
            temp += firs.second;
            pair<int,char> secon ;
            if(!pq.empty()){
                secon = pq.top(); pq.pop();
                temp += secon.second;
            }
            
            if(firs.first-1>0) pq.push({firs.first-1,firs.second});
            
            if(secon.first-1>0) pq.push({secon.first-1,secon.second});

        }
        return temp;
    }
};

// a 3
// b 1
// 2 a
// 0 b