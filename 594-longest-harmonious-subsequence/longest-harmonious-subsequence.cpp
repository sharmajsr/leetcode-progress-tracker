class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxAns = 0;
        unordered_map<int,int>um;
        for(auto i : nums){
            ++um[i];
        }
        for(auto i : um ){
            int temp;
            if(um.find(i.first-1) != um.end()){
                temp = i.second + um[i.first-1];
                maxAns = max(maxAns,temp);
            }
            if(um.find(i.first+1) != um.end()){
                temp = i.second + um[i.first+1];
                maxAns = max(maxAns,temp);
            }
        }
        return maxAns;
    }
};