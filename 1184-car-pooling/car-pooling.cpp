class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>v(1002,0);
        int temp = 0;
        for(auto i : trips){
            v[i[1]]+=i[0];
            v[i[2]]-=i[0];
        }
        for(int i= 0; i< 1002; i++){
            temp += v[i];
            if(temp > capacity){
                return false;
            }
        }
        return true;
    }
};