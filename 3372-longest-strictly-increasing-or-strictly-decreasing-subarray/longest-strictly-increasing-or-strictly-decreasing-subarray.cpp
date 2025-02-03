class Solution {
public:
    int findLis(vector<int>nums){
        int n = nums.size(),maxL = 1 , lsi = 1,dsi = 1;
        vector<int>lis(n,1);
        for(int i = 1 ; i < n ; i++){
            if(nums[i-1]<nums[i]){
                ++lsi;
            }else{
                lsi = 1;
            }
            if(nums[i-1]>nums[i]){
                ++dsi;
            }else{
                dsi =1 ;
            }
            
            maxL = max(maxL,lsi);
            maxL = max(maxL,dsi);
        }
        return maxL;

    }
    int findLds(vector<int>nums){
        int n = nums.size(),maxL = 1 ;
        vector<int>lis(n,1);
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] < nums[j] and lis[j]+1 > lis[i]){
                    lis[i] = lis[j] + 1;
                    maxL = max(maxL,lis[i]);
                }
            }
        }
        return maxL;

    }
    int longestMonotonicSubarray(vector<int>& nums) {
        vector<int>nums1 = nums;
        // reverse(nums1.begin(),nums1.end());
        // int lis = findLis(nums);
        // int lds = findLds(nums);
        // cout<<lis<<" "<<lds<<endl;
        return findLis(nums);
    }
};