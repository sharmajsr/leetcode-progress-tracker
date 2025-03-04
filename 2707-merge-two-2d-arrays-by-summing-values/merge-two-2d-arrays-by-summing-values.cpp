class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        vector<vector<int>>ans;
        for(auto i : nums1){
            int id = i[0];
            int val = i[1];
            if(mp.find(id) != mp.end()){
                mp[id]+=val;
            }else{
                mp[id]=val;
            }
        }
        for(auto i : nums2){
            int id = i[0];
            int val = i[1];
            if(mp.find(id) != mp.end()){
                mp[id]+=val;
            }else{
                mp[id]=val;
            }
        }
        for(auto i : mp){
            ans.push_back({i.first,i.second});
        }
        return ans;
    }
};