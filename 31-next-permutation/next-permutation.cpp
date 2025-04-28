class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size(), i;
        i=n-2;
        for(; i>=0 ;i--){
            // cout<<i<<" "<<nums[i]<<endl;
            if(nums[i+1] > nums[i]){
                int j= i+1 , minNumIdx=i+1;
                for(int k= j; k<n;k++){
                    if(nums[k]>nums[i]){
                        if(nums[k] < nums[minNumIdx]){
                            minNumIdx = k;
                            // cout<<"minNumIdx : " <<nums[k]<<endl;
                        }
                    }
                }
                swap(nums[i],nums[minNumIdx]);
                sort(nums.begin()+i+1,nums.end());
                break;
            } 
        }
        if(i == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        
    }
};