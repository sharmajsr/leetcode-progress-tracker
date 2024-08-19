class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0 ,cnt = 0;
        unordered_map<char,int>um;
        vector<pair<int,char>>v;
        for(auto i:word){
            if( i >= 'a' && i <= 'z')
            ++um[i];
        }
        for(auto i : um){
            v.push_back({i.second, i.first});
        }
        sort(v.begin(),v.end(),greater<>());
        for(int i=0;i<v.size();i++){
            if(i%8 == 0){
                ++cnt;
            }
            ans += (v[i].first * cnt);
            // cout<<i<<" "<<v[i].first<<" "<<v[i].second<<" "<<cnt<<" "<<ans<<endl;
        }
        return ans;

    }
};

//aabbccddeeffgghhiiiiii
// a - 2
// b - 2
// c - 2
// d - 2
// e - 2
// f - 2
// g - 2
// h - 2
// i - 6 