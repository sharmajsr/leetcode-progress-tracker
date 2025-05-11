class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minH;
        for(int i = 0 ; i < n ; i++){
            // cout<<abs(arr[i]-x)<<" "<<arr[i]<<endl;
            minH.push({abs(arr[i]-x),arr[i]});
        }
        while(!minH.empty() and k > 0 ){
            ans.push_back(minH.top().second);minH.pop();
            --k;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};