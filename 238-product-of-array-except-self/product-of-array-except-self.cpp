class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size() , product = 1 , countOfZero =0 ;
        vector<int>ans(n,0);
        for(auto i : nums){
            if(i == 0 ){
                countOfZero += 1;
            }else{
                product *= i;
            }
        }
        for(int i=0; i < n; i++ ){
            if(countOfZero > 0 ){
                if(nums[i] != 0 or countOfZero > 1 ){
                    ans[i]=0;
                }else{
                    ans[i] = product;
                }
            }else{
                ans[i] = product/nums[i];
            }
        }
        return ans;
    }
};