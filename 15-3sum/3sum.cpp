class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>se;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for(int i = 0 ;i < n;i++){
            int j = i+1 ,k = n-1;;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0 ){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    se.insert(temp);
                    ++j;
                    --k;
                    while(j < n and nums[j] == nums[j-1]) ++j;
                    while(k>=0 and nums[k] == nums[k+1])   --k;
                }else if(sum > 0 ){
                    --k;
                }else{
                    ++j;
                }
            }
        }
        for(auto i : se)   ans.push_back(i); 
        return ans;
    }
};