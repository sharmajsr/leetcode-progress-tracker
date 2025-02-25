class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(),ans =0 ;
        double currTimeTaken = 0.0 ;
        vector<pair<int,int>>vp;
        for(int i= 0; i <n; i++){
            vp.push_back({position[i],speed[i]});
        }
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        for(int i=0;i<n;i++){
            int pos = vp[i].first;
            int speed = vp[i].second;
            double tt = double(target-pos)/speed;
            int tt1 = tt;
            if(currTimeTaken < tt){
                currTimeTaken = tt;
                ++ans;
            }

        }
        return ans;
    }
};