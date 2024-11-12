class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,n=nums.size();
        vector<int>ans;
        vector<pair<int,int>>helper;
        for(int i= 0;i<n;i++){
            helper.push_back({nums[i],i});
        }
        sort(helper.begin(),helper.end());
        while(i<j){
            int sum = helper[i].first + helper[j].first;
            if(sum==target){
                ans.push_back(helper[i].second);
                ans.push_back(helper[j].second);
                break;
            }
            else if(sum > target){
                --j;
            }
            else{
                ++i;
            }
        }
        return ans;
    }
};