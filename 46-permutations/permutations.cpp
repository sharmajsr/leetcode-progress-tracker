class Solution {
public:
    void permutations(vector<int>nums, vector<int>op, vector<vector<int>>&ans){
        int n = nums.size();
        if(n == 0){
            ans.push_back(op);
            return ;
        }
        
        for(int i=0;i<n;i++){
            vector<int>se = nums;
            se.erase(se.begin()+i);
            op.push_back(nums[i]);
            permutations(se,op,ans);
            op.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        permutations(nums, op,ans);

        return ans;
    }
};