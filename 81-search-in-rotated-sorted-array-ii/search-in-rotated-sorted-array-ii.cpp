class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        sort(nums.begin(),nums.end());
        while(low<=high){
            int mid = ( low + high )/2;
            if(nums[mid] == target){
                return true;
            }else if(nums[mid] <= nums[high]){
                if(target > nums[mid] and target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }else{
                if(target >= nums[low] and target <= nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
        }
        return false;
    }
};