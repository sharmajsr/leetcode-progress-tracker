class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        vector<vector<int>> fans;
        int n = nums.size();
        for(int i =0 ; i < n-2 ;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" "<<sum<<endl;
                if(sum == 0){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.insert(temp);
                    while(j<k and nums[j] == nums[j+1])    j++;
                    while(j<k and nums[k] == nums[k-1])    k--;
                    ++j;
                    --k;
                    // cout<<j<<" "<<k<<endl;
                    
                }else if(sum >0){
                    --k;
                }else{
                    ++j;
                }
            }
        }
        for(auto i : ans){
            fans.push_back(i);
        }
        return fans;
    }
};

// [-1,0,1,2,-1,-4]
// [-4 , -1 ,-1 ,0 , 1, 2]