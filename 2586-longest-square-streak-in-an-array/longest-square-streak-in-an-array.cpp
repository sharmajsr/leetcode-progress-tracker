class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int>um;
        int maxCount= 0, maxElement = INT_MIN;
        for(auto i: nums){
            ++um[i];
            maxElement = max(maxElement,i);
        }
        for(auto i:nums){
            int cnt = 1 ;
            long long int j = i ;
            while(j*j <= maxElement and um.find(j*j) != um.end()){   
                j= j*j; ++cnt;
                // cout<<i<<" "<<j<<" "<<cnt<<endl;
            }
            maxCount = max(maxCount,cnt);
        }
        return maxCount == 1 ? -1 : maxCount;
    }
};