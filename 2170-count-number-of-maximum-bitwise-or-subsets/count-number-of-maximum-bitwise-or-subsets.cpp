class Solution {
public:
    int findSubset(int curVal, int curIndex,int targetVal,vector<int>nums,int &cnt){
        
        
        if(curIndex == nums.size()){
            return curVal == targetVal ? 1 : 0;
        }

        return findSubset( curVal ,curIndex+1,targetVal,nums,cnt) + 
                findSubset( curVal | nums[curIndex] ,curIndex+1,targetVal,nums,cnt);

    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(),cnt = 0;
        int maxBitwise = 0 ;
        for(auto i : nums) maxBitwise |= i;
        int ans = findSubset(0,0,maxBitwise,nums,cnt);
        // cout<<ans << " " <<cnt<<endl;
        return ans;
    }
};
//  2 - 3
//  2,2 - 3
//  2,2,2 - 1
