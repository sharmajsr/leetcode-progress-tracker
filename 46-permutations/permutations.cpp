class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>cur,int n){
        if(cur.size() == n ){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            cur.push_back(nums[i]);
            vector<int>temp = nums;
            temp.erase(temp.begin()+i);
            solve(temp,ans,cur,n);
            cur.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,ans,{},nums.size());
        return ans;
    }
};