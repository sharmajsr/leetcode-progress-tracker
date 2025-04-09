class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>um;
        int ans = 0 ;
        for(auto i : nums)  ++um[i];
        for(auto i : um ){
            if(i.first > k) ++ans;
            else if(i.first < k) return -1;
        }
        return ans;
    }
};
