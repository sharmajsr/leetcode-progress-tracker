class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>p;
        
        int i = 0;
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            p.push_back({nums[i],i});
        }
        sort(p.begin(),p.end());
        int j=n-1;
        while(i<j){
            int sum = p[i].first + p[j].first;
            cout<<i<<" "<<j<<" "<<sum<<" "<<target<<endl;
            if(sum == target){
                ans.push_back(p[i].second);
                ans.push_back(p[j].second);
                return ans;
            }
            else if(sum>target){
                 --j;
            }
            else if(sum <target){
                ++i;
            }
        }
        return ans;
    }
};