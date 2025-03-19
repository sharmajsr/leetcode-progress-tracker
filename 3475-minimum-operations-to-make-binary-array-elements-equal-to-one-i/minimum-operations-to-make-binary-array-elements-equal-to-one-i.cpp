class Solution {
public:
    void switche(int i,vector<int>&nums){
        nums[i]=1;
        nums[i+1] = nums[i+1] == 1 ? 0 : 1; 
        nums[i+2] = nums[i+2] == 1 ? 0 : 1; 
    }
    int minOperations(vector<int>& nums) {
        int n =nums.size(),cnt = 0 ;
        for(int i= 0; i< n-2;i++){
            if(nums[i] == 0){
                switche(i,nums);
                ++cnt;
            }
            
        }
        for(auto i : nums)  if(i == 0)  return -1;
        return cnt;
    }
};

