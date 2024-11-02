class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // vector<int>lis(1000,1);
        unordered_map<int,int>lis;
        vector<pair<int,int>>vp;
        int n = pairs.size() , ans= 0;
        for(auto i : pairs){
            vp.push_back({i[0],i[1]});
        }
        sort(vp.begin(),vp.end());

        for(int i=1 ; i<n ; i++){
            for(int j=0; j <i ; j++){
                    if(vp[j].second >= vp[i].first)   continue;
                    else    lis[vp[i].second] = max(lis[vp[i].second], 1+ lis[vp[j].second]);
                    ans = max(ans,lis[vp[i].second]);
                    // cout<<i<< " "<<j<<" " <<vp[i].second<<" "<<lis[vp[i].second]<<endl;
            }
        }
        // for(int i=1; i<10;i++){
        //     cout<<i<<" "<<lis[i]<<endl;
        // }
        return ans+1;
    }
};