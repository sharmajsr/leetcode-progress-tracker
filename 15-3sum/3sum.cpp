class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>se;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int j=  i+1 ;
            int k = n-1 ;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                // cout<<nums[i]<<" "<<nums[j]<<" " <<nums[k]<<" " <<sum<<endl;
                if(sum == 0){
                    vector<int>cur;
                    cur.push_back(nums[i]);
                    cur.push_back(nums[j]);
                    cur.push_back(nums[k]);
                    se.insert(cur);
                    
                    while(nums[j] == nums[j+1] && j+1<k)
                        ++j;
                    while(nums[k] == nums[k-1] && k-1>j)
                        --k;
                    ++j;
                    --k;
                }
                else if(sum>0){
                    --k;
                }
                else{
                    ++j;
                }
            }
            // ++i;
        }
        for(auto i :se){
            ans.push_back(i);
        }
        return ans;
    }
};