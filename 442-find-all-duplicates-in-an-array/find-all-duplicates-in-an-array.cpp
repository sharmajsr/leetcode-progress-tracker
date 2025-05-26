class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i= 0 ; i <nums.size(); i++){
            int el = nums[i];
            if(nums[abs(el)-1] < 0 ){
                ans.push_back(abs(el));
            }
            // cout<<i<<" "<<el<<endl;
            nums[abs(el)-1] *= -1;
        }
        return ans;
    }
};

// [4,3,2,7,8,2,3,1]
// []