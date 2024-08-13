class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap;
        for(auto i : stones){
            maxHeap.push(i);
        }
        while(maxHeap.size() > 1){
            int firstHeaviest = maxHeap.top();
            maxHeap.pop();
            int secondHeaviest = maxHeap.top();
            maxHeap.pop();
            int diff = abs(firstHeaviest - secondHeaviest);
            maxHeap.push(diff);
        }
        return maxHeap.top();
    }
};