class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int i = 0 , j =0 ,n = nums.size(), sum = 0;
        int minLen = INT_MAX ;
        while( j < n){
            sum += nums[j];
            if(sum < target){
                ++j;
            }else if( sum > target){
                while(sum > target){
                    minLen = min(minLen, j-i+1);
                    sum -= nums[i];
                    ++i;
                }
                if(sum == target)   minLen = min(minLen, j-i+1);
                ++j;
            }else if(sum == target){
                // if(sum == target){
                    minLen = min(minLen, j-i+1);
                // }
                // minLen = min(minLen, j-i+1);
                // sum -= nums[i];
                // ++i;
                ++j;
            }
            // cout<<i<< " "<<j<<" "<<sum<<" "<<minLen<<endl;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

// [2,3,1,2,4,3]
// i = 4
// j = 5
// sum = 7
// minLen = 3