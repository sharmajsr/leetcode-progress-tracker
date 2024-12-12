class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0 ;
        priority_queue<int>maxHeap;
        for(auto i : gifts){
            maxHeap.push(i);
        }
        while(k--){
            auto top = maxHeap.top();
            maxHeap.pop();
            int n = pow(top,0.5);
            maxHeap.push(n);
        }
        while(!maxHeap.empty()){
            auto top = maxHeap.top();
            maxHeap.pop();
            ans+=top;
        }
        return ans;
    }
};
