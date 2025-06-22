class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i= 0; i< n-2; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0 ){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.insert(temp);
                    // ++j;--k;
                    while( j < n-1 and nums[j] == nums[j+1]) ++j;
                    while( k > 0 and nums[k] == nums[k-1]) --k;
                    ++j;
                    --k;
                    
                }else if(sum > 0 ){
                    --k;
                }else{
                    ++j;
                }
            }
        }
        vector<vector<int>>ans1;
        for(auto i : ans){
            ans1.push_back(i);
        }
        return ans1;
    }
};