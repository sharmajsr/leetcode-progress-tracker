class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       int n = nums.size(),  maxLis = 1 , maxLisIdx = 0;
       vector<int> ans;
       vector<int>lis(n,1),prev(n);
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        prev[i] = i ;
            for(int j= 0;j <i ;j++){
                if(nums[i] % nums[j] == 0 and lis[i] <= lis[j]){
                    lis[i] = lis[j]+1;
                    prev[i] = j;
                }
                if(lis[i]  > maxLis){
                    maxLis = lis[i];
                    maxLisIdx = i;
                    
                }
            }
        }
        // cout<<maxLis<<" "<<nums[maxLisIdx]<<" "<<lis[maxLisIdx]<<endl;
        // for(int i=0 ;i < n ;i++)    cout<<i<<" "<<nums[i]<<" "<<lis[i]<<" "<<prev[i]<<endl;
        while(prev[maxLisIdx] != maxLisIdx ){
                ans.push_back(nums[maxLisIdx]);
                maxLisIdx = prev[maxLisIdx];
        }
        ans.push_back(nums[maxLisIdx]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};