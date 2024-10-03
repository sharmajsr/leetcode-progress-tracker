class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        int pos =1;
        map<int,int>om;
        unordered_map<int,int>um;
        for(auto i : arr){
            ++om[i];
        }
        for(auto i : om){
            um[i.first] = pos++;
        }
        for(int i : arr){
            ans.push_back(um[i]);
        }
        return ans;
    }
};