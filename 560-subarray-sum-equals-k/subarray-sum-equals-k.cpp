class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt =0 , n = nums.size() ,sum = 0 ;
        unordered_map<int,int>um;
        um[0]=1;
        for(int i= 0; i<n;i++){
            sum += nums[i];
            int diff = sum-k;
            if(um.find(diff) != um.end()){
                cnt += um[diff];
            }
            ++um[sum];
        }

        return cnt;
        
    }
};