class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>um;
        vector<vector<string>>ans;
        for(auto i : strs){
            string temp = i;
            sort(temp.begin(),temp.end());
            um[temp].push_back(i);
        }
        for(auto i : um){
            ans.push_back(i.second);
        }
        return ans;
    }
};