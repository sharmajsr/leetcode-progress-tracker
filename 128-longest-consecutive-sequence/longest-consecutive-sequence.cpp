class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int>previousNotPresent;
        unordered_map<int,int>um;
        int maxLen = 0 ;
        for(auto i : nums){
            ++um[i];
            // previousNotPresent.push_back(i)
        }
        for(auto i : nums){
            if(um.find(i-1) == um.end())
            previousNotPresent.push_back(i);
        }
        for(auto k : previousNotPresent){
            int temp = 0 , i=k ;
            while( um.find(i) != um.end() ){
                ++i;
                ++temp;
            }
            maxLen = max(maxLen,temp);
        }
        return maxLen;
    }
};