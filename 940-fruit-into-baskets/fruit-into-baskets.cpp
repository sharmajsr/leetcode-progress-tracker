class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n = f.size() , maxLen = 0 ;
        int i =0 , j= 0 , k =2;

        unordered_map<int,int>um;

        while(j<n){
            ++um[f[j]];
            if(um.size() > k){
                --um[f[i]];
                if(um[f[i]] == 0 ){
                    um.erase(f[i]);
                }
                ++i;
            }
            if(um.size() <= k)maxLen = max(maxLen,j-i+1);
            ++j;
        }
        return maxLen;
    }
};