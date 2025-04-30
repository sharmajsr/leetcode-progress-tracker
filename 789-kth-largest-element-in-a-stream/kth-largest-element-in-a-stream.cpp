class KthLargest {
public:
    int K ;
    priority_queue<int,vector<int>,greater<int>>maxH;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto i : nums){
            maxH.push(i);
            if(maxH.size() > k ){
                maxH.pop();
            }
        }
    }
    
    int add(int val) {
        maxH.push(val);
        if(maxH.size() > K ){
                maxH.pop();
            }
            return maxH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */