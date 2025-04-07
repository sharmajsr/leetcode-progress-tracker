class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>um;
        vector<int>ans;
        for(auto i : nums) ++um[i];
        for(auto i : um) if(um[i.first] > 1)  ans.push_back(i.first);
        return ans;
    }
};