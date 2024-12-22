class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(),minimumOperations = 0 ;
        unordered_map<int,int>freq;
        for(auto i : nums)  ++freq[i];
        int i = 0 ;
        // cout<<"FReq size "<<freq.size()<<endl;
        while(i<n){
            
            // cout<<i<<" "<<n-i<<" "<<freq.size()<<endl;
            int size = n- i;
            if(freq.size() == size){
                return minimumOperations;
            }else{
                // cout<<"in else : "<<i<<endl;
                int j = i;
                for(;j<n and j<i+3;j++){
                    --freq[nums[j]];
                    // cout<<nums[j]<<" "<<freq[nums[j]]<<endl;
                    if(freq[nums[j]] == 0)    freq.erase(nums[j]);
                }
                i=j;
            }
            minimumOperations++;
        }
        return minimumOperations;
    }
};