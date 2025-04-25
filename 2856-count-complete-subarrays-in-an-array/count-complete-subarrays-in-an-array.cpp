class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>um,um1;
        for(auto i : nums)  ++um[i];
        int numberOfDistinctEl = um.size();
        int i =0 , j =0 , ans = 0,n = nums.size() ;
        for(int i=0;i<n;i++){
            um1.clear();
            for(int j=i;j<n;j++){
                ++um1[nums[j]];
                if(um1.size() == numberOfDistinctEl) ++ans;
            }
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;

    }
};