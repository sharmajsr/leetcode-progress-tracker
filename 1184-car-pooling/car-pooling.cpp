class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>v(1003,0);
        priority_queue<
        vector<int>,vector<vector<int>>,greater<vector<int>>
        >minH;
        for(auto i : trips){
            // vector<int>temp = {};
            // temp.push_back();
            minH.push({i[1],i[2],i[0]});
        }
        while(!minH.empty()){
            
            int start = minH.top()[0];
            int end = minH.top()[1];
            int cap = minH.top()[2];
            if(cap > capacity)  return false;
            minH.pop();
            // cout<<start<<" "<<end<<" "<<cap<<endl;

            v[start]-=cap;
            v[end]+=cap;
        }
        v[0]+=capacity;
        for(int i=1;i<1002;i++){
            v[i]+=v[i-1];
            if(v[i] < 0 )   return false;
        }
        return true;
    }
};