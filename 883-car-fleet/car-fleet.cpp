class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int  n = position.size() ,cnt = 0;
        vector<pair<int,double>>vp ; 
        for(int i =  0 ;i  < n ;i++){
            vp.push_back({position[i],(1.0*(target-position[i])/speed[i])});
        }
        sort(vp.begin(),vp.end());
        stack<float>st;
        for(int i= n-1 ; i>=0 ;i--){
            // cout<<vp[i].first<<" " <<vp[i].second<<endl; 
            if(st.empty()){
                st.push(vp[i].second);
                ++cnt;
            }else if(!st.empty() and st.top() < vp[i].second){
                st.push(vp[i].second);
                ++cnt;
            }
        }
        return cnt;
    }
};
// t = 12
// position = [10 , 8 , 0 , 5 , 3]
// t - pos = [ 2 , 4 , 12 , 7 , 9 ]
// speed = [2 , 4 , 1 , 1 , 3]
// time = [ 1, 1 , 12 , 7 ,3]
// ts = [ 1, 1, 7 ,3 , 12]
