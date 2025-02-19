class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap;
        for(auto i : stones){
            maxHeap.push(i);
        }
        while(!maxHeap.empty()){
            if(maxHeap.size() == 1) break;
            int x = maxHeap.top(); maxHeap.pop();
            int y = maxHeap.top(); maxHeap.pop();
            if( x == y){
                continue;
            }else{
                if(x> y) {
                    maxHeap.push(x-y);
                }else{
                    maxHeap.push(y-x);
                }
            }
        }
        return maxHeap.size() == 0 ? 0 : maxHeap.top();
    }
};