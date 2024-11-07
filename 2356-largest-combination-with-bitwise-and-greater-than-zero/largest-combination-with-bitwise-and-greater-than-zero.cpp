class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        if(candidates.size() == 1)  return 1;
        int ans = 0 ;
        for(int i=0;i<25;i++){
            int cnt =0 ;
                for(auto j : candidates){
                    if((j & (1 <<i ))> 0 ){ // check if ith bit is set in integer j
                        ++cnt;
                    }
                }
                ans = max(ans,cnt);
        }
        return ans;
       
    }
};