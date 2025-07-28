class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
        // maxHeap.empty();
        // minHeap.empty();
    }
// 
//           
//  2          3
//  1          4
// max       min
    
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
        }else if (num >= maxHeap.top() ){
            minHeap.push(num);
        }else{
            maxHeap.push(num);
        }
        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size() > maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            return 1.0*(minHeap.top() + maxHeap.top()) * 0.5;
        }else if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }else{
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */