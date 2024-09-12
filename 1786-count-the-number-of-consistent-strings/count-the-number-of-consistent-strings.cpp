class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>um;
        for(auto i : allowed) ++um[i];
        int ans = 0; 
        for(auto word : words){
            int flag = 0;
            for(auto i : word){
                if(um.find(i) == um.end()){
                    flag =1;
                    break;
                }
            }
            if(!flag) ++ans;
        }
        return ans;
    }
};