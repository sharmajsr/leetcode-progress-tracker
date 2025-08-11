class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0, res= 0;
        for(int n: nums ){
            if( majority == 0){
                res = n; 
            }
            majority += res == n ? 1 : -1;
        }
        return res;
    }
};

// [2,2,1,1,1,2,2]
// majority = 0
// res = 3 
// n : 2
