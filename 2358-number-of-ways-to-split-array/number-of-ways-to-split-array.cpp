class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0 , n= nums.size();
        vector<long long>rightSum(n,0);
        long long sum = 0;
        sum=0;
        for(int i=n-1 ; i >= 0; i--){
            sum+=nums[i];
            rightSum[i]=sum;
        }
        sum = nums[0];
        for(int i=1;i<n;i++){
            if(sum >= rightSum[i] ){
                ++ans;
            }
            sum+=nums[i];
        }
        return ans;
    }
};