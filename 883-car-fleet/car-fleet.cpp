class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans , n= speed.size();
        stack<float>st;
        vector<pair<int,int>>v;
        for(int i = 0; i <n; i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        for(int i = n -1; i >=0 ; i--){
            float time = (target - v[i].first) * 1.0/v[i].second;
            // cout<<i<<" "<<position[i]<<" "<<speed[i]<<" "<<time<<endl;
            if(st.empty()) st.push(time);
            else if(st.top() < time) st.push(time);
        }
        return st.size();
    }
};