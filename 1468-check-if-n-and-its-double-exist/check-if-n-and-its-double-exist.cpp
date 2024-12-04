class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>um;
        for(auto i : arr){
            ++um[i];
        }
        if(um[0] > 1){
            return true;
        }
        for(auto i : arr){
            if(i!=0 and um.find(i*2) !=um.end()){
                return true;
            }
        }
        return false;
    }
};