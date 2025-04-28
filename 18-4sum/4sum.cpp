class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>se;
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n ; i++ ){
            for(int j = i+1 ; j < n ; j++ ){
                int k= j+1 , l = n-1;
                while(k<l){
                    long long t1 = nums[i] + nums[j] , t2 = nums[k] + nums[l],t3;
                    t3 = t1 + t2;
                    if(t3 == target){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        sort(temp.begin(),temp.end());
                        se.insert(temp);
                        ++k;
                        --l;
                        while(k<n and nums[k] == nums[k-1]) ++k;
                        while(l>=0 and nums[l] == nums[l+1]) --l;
                        
                    }else if(t3 > target){
                        --l;
                    }else{
                        ++k;
                    }
                } 
                // for(int k = j+1 ; k < n ; k++ ){
                //     for(int l = k+1 ; l < n ; l++ ){
                //         long long t1 = nums[i] + nums[j] , t2 = nums[k] + nums[l],t3;
                //         t3 = t1 + t2;
                //         if(t3 == target){
                //             vector<int>temp;
                //             temp.push_back(nums[i]);
                //             temp.push_back(nums[j]);
                //             temp.push_back(nums[k]);
                //             temp.push_back(nums[l]);
                //             sort(temp.begin(),temp.end());
                //             se.insert(temp);
                //         }
                //     }
                // }
            }
        }
        for(auto i : se){
            ans.push_back(i);
        }
        return ans;
    }
};