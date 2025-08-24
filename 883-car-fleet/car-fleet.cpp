class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<int>left(n,0);
        vector<pair<int,int>>vp;
        stack<double>st;
        for(int i = 0 ;i < n ; i++){
            left[i] = target - position[i];
            vp.push_back({left[i],i});
        }
        sort(vp.begin(), vp.end());
        for(int i = 0 ; i< n ; i++){
            double reachTime =  ( vp[i].first *1.0 )/ (speed[vp[i].second] * 1.0 ) ;  
            // cout<<i<<" "<<reachTime<<endl;
            if(st.empty()) { 
                st.push(reachTime);
            }else{
                if(st.top() == reachTime or st.top() > reachTime) continue;
                st.push(reachTime);
            }
        }
        return st.size();
    }
};
// [2,4,7,9,12]
// [2,4,1,3,1]
// 1 , 1 ,7 , 3 , 12
