class Solution {
public:

    int minOperations(vector<int>& nums) {
        int cnt = 0 , n = nums.size();
        for(int i=0;i<n;i++){
            if((cnt + nums[i])%2 == 0 ){
                // swi(i,nums);
                ++cnt;
            }
        }
        return cnt;
    }
};

// cnt = 1
// 1000
// 1111