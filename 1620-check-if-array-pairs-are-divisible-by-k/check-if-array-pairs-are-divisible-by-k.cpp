class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>um;
        for(auto i : arr){
            int rem = ((i%k)+k)%k;
            ++um[rem];
        }
        if( um[0] % 2 )  return false;
        for(auto i : um){
            if(i.first == 0 or i.first == k)    continue;
            int cnt = i.second;
            int otherElementCnt = um[k-i.first];
            cout<<i.first<<" "<<k-i.first<<" "<<cnt<<" "<<otherElementCnt<<endl;
            if( cnt != otherElementCnt){
                return false;
            }
        }
        return true;
    }
};