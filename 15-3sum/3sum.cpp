class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>ans;
        vector<vector<int>>a1;
        sort(nums.begin(),nums.end());
        for(int i= 0 ;i < nums.size() ; i++){
            int j = i + 1 ;
            int k = n - 1 ;
            while(j<k){
                int su1 = nums[i] + nums[j] + nums[k];
                if(su1 == 0 ){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.insert(temp);
                    // j +=1 ;
                    // k -=1 ;
                    while(j < n-1 and nums[j] == nums[j+1])        j += 1 ;
                    while(k > 0 and nums[k] == nums[k-1] )         k -= 1 ;
                    j += 1 ;
                    k -= 1 ;
                }
                else if(su1  < 0){
                    j += 1;
                }
                else{
                    k -= 1;
                }
            }
        }
        for(auto i : ans){
            a1.push_back(i);
        }
        return a1;
    }
};