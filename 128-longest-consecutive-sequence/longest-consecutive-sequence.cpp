class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        unordered_map<int,int>um;
        int ans=0;
        for(auto i : nums)  um[i]=1;
        // cout<<um[-10]<<endl;
        for(int i=0;i<nums.size();i++){
            
            int f = nums[i]-1;
            // cout<<f<<" "<<nums[i]<<" "<<um[f]<<endl;
            if(um[f] == 0 ){
                // cout<<nums[i]<<" "<<f<<endl;
                int p = nums[i];
                // cout<<f<<" " <<nums[i]<<" "<<p<<" " <<p-nums[i]<<endl;
                while(um[p] > 0)   ++p;
                
                ans= max(p-nums[i],ans);
            }
        }
        return ans;
    }
};