class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<4) return {};
        vector<vector<int>>a1;
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        // cout<<"After sorting\n";
        for(int i = 0 ; i < nums.size()-3 ; i++){
            // cout<<"Inside ith loop "<<i<<endl;
            for(int j = i+1 ; j < nums.size()-2 ; j++ ){
                // cout<<"Inside jth loop "<<j<<" "<<nums.size()<<endl;
                int k = j+1;
                int l = n-1;
                while( k < l ){
                    long long s3 = nums[i] + nums[j] ;
                    long long s2 =  nums[k] + nums[l] ;
                    long long s1 = s3 + s2;
                    if(s1 == target ){
                        vector<int>temp;

                        temp.push_back(nums[i]);  temp.push_back(nums[j]);
                        temp.push_back(nums[k]);  temp.push_back(nums[l]);
                        // sort(temp.begin(),temp.end());
                        // k+=1;
                        // l-=1;
                        ans.insert(temp);
                        while( k < n-1 and nums[k] == nums[k+1])  k+=1;
                        while( l > 0 and nums[l] == nums[l-1])    l-=1;
                        k+=1;
                        l-=1;
                    }
                    else if(s1 > target ){
                        l -= 1;
                    }else{
                        k += 1;
                    }
                }

            }
        }

        // cout<<"After ith loop\n";
        for(auto i : ans){
            a1.push_back(i);
        }
        return a1;
    }
};