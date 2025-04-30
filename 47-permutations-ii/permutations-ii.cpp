class Solution {
public:
    void solve(vector<int> nums,vector<int>cur,set<vector<int>>&ans,int n){
        if(cur.size() == n ){
            ans.insert(cur);return;
        }
        for(int i=0;i<nums.size();i++){
            cur.push_back(nums[i]);
            vector<int>v = nums;
            v.erase(v.begin()+i);
            solve(v,cur,ans,n);
            cur.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        vector<vector<int>> ans1;
        solve(nums,{},ans,nums.size());
        for(auto i : ans)   ans1.push_back(i);
        return ans1;
    }
};