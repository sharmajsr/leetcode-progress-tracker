class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size() , cnt = 0;
        vector<int>ans;
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0 ;
            }
        }
        for(auto i : nums){
            if(i == 0 ) ++cnt;
            else    ans.push_back(i);
        }
        while(cnt--)    ans.push_back(0);
        return ans;
    }
};