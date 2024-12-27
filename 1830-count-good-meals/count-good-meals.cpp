class Solution {
public:
    int countPairs(vector<int>& del) {
        int MOD =1e9+7;
        int  ans=0;
        vector<int>powerOfTwo;
        unordered_map<int,int>um;
        for(int i=0;i<22;i++){
            powerOfTwo.push_back(pow(2,i));
        }
        for(int i=0;i<del.size();i++){
            for(int j=0;j<23;j++){
                int diff = powerOfTwo[j]-del[i];
                if(um.find(diff) != um.end() ){
                    ans +=    um[diff] % MOD;
                    ans%=MOD;
                }
            }
            ++um[del[i]];
        }
        return ans;
    }
};