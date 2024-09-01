class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        vector<pair<int,int>>temp;
        for(auto i : arr){
            temp.push_back({abs(i-x),i});
        }
        sort(temp.begin(),temp.end());
        for(int i= 0 ; i < temp.size()  && i <k ;i++){
            ans.push_back(temp[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};