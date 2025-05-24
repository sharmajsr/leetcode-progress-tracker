class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>vp;
        for(int i= 0; i<nums.size(); i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.begin(),vp.end());
        int i = 0 , j = nums.size()-1;
        while(i<j){
            int sum = vp[i].first + vp[j].first;
            if(sum == target){
                return {vp[i].second,vp[j].second};
            }else if(sum > target){
                --j;
            }else{
                ++i;
            }

        }
        return {};
        
    }
};