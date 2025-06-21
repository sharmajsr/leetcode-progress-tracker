class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>um;
        for(auto i : nums)  ++um[i];

        for(int i=0;i<n;i++){
            if(um[nums[i]]>1) return true;
        }
        
        return false;
    }
};