class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>ans;
        vector<vector<int>>an1;
        sort(nums.begin(),nums.end());
        for(int i = 0 ;i < nums.size(); i++){
            int j = i+1 , k = nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.insert(temp);
                    ++j;
                    --k;
                    while(j<n and  nums[j] == nums[j-1]) ++j;
                    while(k>=0 and nums[k] == nums[k+1]) --k;
                }else if(sum > 0){
                    --k;
                }else{
                    ++j;
                }
            }
        }
        for(auto i : ans){
            an1.push_back(i);
        }
        return an1;
    }
};