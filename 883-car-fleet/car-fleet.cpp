class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        stack<double>st;
        vector<pair<int,int>>vp;
        for(int i = 0 ; i < n ; i++){
            vp.push_back({position[i],speed[i]});
        }
        sort(vp.begin(),vp.end());
        for(int i= n-1;i>=0;i--){
            double time1  = double(target - vp[i].first)/vp[i].second;

            // if(!st.empty())
            // cout<<float(time1)<<" " <<st.top()<<endl;
            if(st.empty())  st.push(time1);
            else if( time1 > st.top()){
                st.push(time1);
            }

        }
        return st.size();
    }
};
 
// c1 : 10 , 12 
// c2 : 8  , 12
// c3 : 0 , 1,2,3,4,5,6,7,8,9,10,11,12
// c4 : 5  , 6, 7, 8, 9, 10, 11, 12
// c5 : 3 , 6 , 9, 12
//A car can not pass another car ahead of it.  c5 will reach with c4