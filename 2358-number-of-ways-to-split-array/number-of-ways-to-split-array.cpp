class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0 , n= nums.size();
        vector<long long>leftSum(n,0),rightSum(n,0);
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            leftSum[i] = sum;
        }
        sum=0;
        for(int i=n-1 ; i >= 0; i--){
            sum+=nums[i];
            rightSum[i]=sum;
        }
        for(int i=1;i<n;i++){
            // cout<<i<<" "<<leftSum[i]<<" "<<rightSum[i]<<endl;
            if(leftSum[i-1] >= rightSum[i] ){
                ++ans;
            }
        }
        return ans;
    }
};