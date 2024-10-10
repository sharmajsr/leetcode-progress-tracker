class Solution {
public:
    static bool comp(const auto &a, const auto&b){
        
    }
    int maxWidthRamp(vector<int>& nums) {
        int n= nums.size(),ans= 0 ;
        int min_seen ,max_width= 0 ;
        vector<pair<int,int>>v;
        for(int i = 0 ; i < n ; i++ ){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        min_seen = v[0].second;
        for(int i= 1 ;i < n;i++){
            int dif = v[i].second - min_seen;
            // cout<<i<<" "<<v[0].second<< min_seen
            ans =max(ans,dif);
            min_seen = min(min_seen,v[i].second);
        }
        return ans;
    }
};
// before sorting
// 0 1 2  3 4 5  
// 6 0 8  2 1 5
//             

// after sorting
// 1 4 3 5 0 2 
// 0 1 2 5 6 8
// min index = 5
// max width = 0