class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n,0);
        for(int i = 0 ; i < n ; i++){
            int k = i + nums[i];
            for(int j = i+1 ; j<n and j <= k ;j++){
                if(v[j] == 0 )  v[j] = v[i]+1;
                else    
                v[j] =min( v[i]+1 , v[j] ) ;
            }
        }
        return v[n-1];
    }
};
// [2,3,1,1,4]
// 