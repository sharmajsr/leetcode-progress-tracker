class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ans = false;
        int n = nums.size();
        int nextH = 0;
        for(int i = 0 ; i <= nextH and i < n; i++){
            nextH = max(nextH,nums[i]+i);
            // cout<<i<<" "<<nextH<<endl;
            if(nextH >= n-1){
                return true;
            }
        }
        return false;
    }
};
// [2,3,1,1,4]
//  nextH = 2
// 

// [1,1,1,1,0]
// [3,2,1,0,4]