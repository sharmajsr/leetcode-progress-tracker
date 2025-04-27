class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>um;
        for(int i=0;i<nums.size();i++)  um[nums[i]] = i;
        for(int i = 0 ; i<nums.size() ; i++){
            int temp = target - nums[i];
            if(um.find(temp) != um.end() and um[temp] != i){
                // cout<<i<<" "<<nums[i]<<" "<<temp<<" "<<um[temp]<<endl;
                ans.push_back(i);
                ans.push_back(um[temp]);
                return ans;
            }
        }
        return ans;
    }
};