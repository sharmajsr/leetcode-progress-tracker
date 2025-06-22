class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt =0 , n = nums.size() ,sum = 0 ;
        unordered_map<int,int>um;
        um[0]=1;
        for(int i= 0; i<n;i++){
            sum += nums[i];
            int diff = sum-k;
            if(diff == 0 ){
                if(um.find(0) == um.end()){
                    cnt += 1;
                    // um[0] = 1; 
                }else
                {
                    // cout<<i<<" "<<sum<<" "<<um[diff]<<endl;
                    cnt += um[diff];
                    // ++um[0];
                }
            } 
            else if(um.find(diff) != um.end()){
                cnt += um[diff];
                // ++um[sum];
            }
            ++um[sum];
        }

        return cnt;
        
    }
};