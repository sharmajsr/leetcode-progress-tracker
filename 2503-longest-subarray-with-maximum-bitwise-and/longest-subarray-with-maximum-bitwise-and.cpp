class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0 , curMax = 0 ,currentStreak= 0 ; 
        int pref = nums[0],curMaxPref = nums[0];
        for(int num : nums) {
            if( num > curMax) {
                curMax =  num;
                ans = currentStreak = 0 ;
            }
            if(num == curMax)   ++currentStreak;
            else     currentStreak = 0; 

            ans = max(ans,currentStreak);
            
        }
        return ans;
    }
};