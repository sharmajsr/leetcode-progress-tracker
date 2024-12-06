class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
       unordered_map<int,int>um;
       int curSum = 0 , numberOfElementsPicked = 0 ;
       for(auto i : banned) ++um[i];
       for(int i = 1 ;i<=n;i++){
            if(curSum + i <= maxSum and um.find(i) == um.end()){
                curSum =curSum + i;
                ++numberOfElementsPicked;
            }
       }
    //    cout<<curSum<<endl;
       return numberOfElementsPicked;
    }
};