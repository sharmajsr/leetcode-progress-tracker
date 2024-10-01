class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>um;
        for(auto i : paths){
            ++um[i[0]];
            if(um.find(i[1]) == um.end() )
            um[i[1]] = 0;
        }
        for(auto i :um){
            if(i.second == 0 )  return i.first;
        }
        return "";
    }
};