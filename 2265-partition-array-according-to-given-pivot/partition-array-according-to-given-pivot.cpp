class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>t1,t2;
        int pivotCnt = 0;
        for(auto i : nums ){
            if(i == pivot){
                ++pivotCnt;
            }else if(i > pivot){
                t2.push_back(i);
            }else{
                t1.push_back(i);
            }
        }
        while(pivotCnt--)    t1.push_back(pivot);
        for(auto i : t2)    t1.push_back(i);
        return t1;
    }
};