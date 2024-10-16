class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())    return "";
        // pair<int,string> values = mp[key];
        string ans;
        int l= 0;
        int h=mp[key].size()-1;
        // for(int i=n;i>=0;i--){
        //     if(values[i].second <= timestamp){
        //         ans= values[i].first;
        //         break;
        //     }
        // }
        while(l<=h){
            int mid = (l+h)/2;
            if(mp[key][mid].first == timestamp){
                return mp[key][mid].second;
                
            }
            else if(mp[key][mid].first > timestamp){
                // ans = values[mid].first;
                // l = mid+1;
                h = mid-1;
            }
            else if(mp[key][mid].first < timestamp){
                // ans = values[mid].first;
                l = mid+1;
            }
        }
        if(h>=0){
            return mp[key][h].second;
        }
        return ans;
    }
};
// timestamp = 1
// l = 0
// h = 0
// mid = 1

// 0 1 2 3
// 1 3 5 7
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */