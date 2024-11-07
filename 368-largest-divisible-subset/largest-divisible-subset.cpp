class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int maxLis = 0 , maxLisIndex = 0, n= nums.size();
        vector<int>lis(n,1);
        vector<int>dis(n);
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            dis[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 and lis[i] < lis[j]+1){
                    lis[i] = lis[j]+1;
                    dis[i] =j;
                }
            }
            if(maxLis < lis[i] ){
                    maxLis = lis[i];
                    maxLisIndex = i;
            }
        }
        while(dis[maxLisIndex] != maxLisIndex){
            ans.push_back(nums[maxLisIndex]);
            maxLisIndex =dis[maxLisIndex];
        }
        ans.push_back(nums[maxLisIndex]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};