class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int MOD=1e9+7;
        sort(nums.begin(),nums.end());
        int l = 0 , n = nums.size();
        int  r = n-1;
        vector<int>power(n);
        power[0]=1;
        for(int i=1;i<n;i++){
            power[i] = (power[i-1]*2) %MOD;
        }
        long long ans = 0;
        while(l<=r){
            if(nums[l] + nums[r] <= target){
                ans = ( (int)ans % MOD + (int)power[r-l] % MOD) % MOD;
                ++l;
            }
            else{
                --r;
            }
        }
        return ans%MOD;
    }
};