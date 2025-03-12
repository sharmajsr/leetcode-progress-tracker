class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
        maxHeap.empty();
        minHeap.empty();
    }
    
    void addNum(int num) {
        if(!minHeap.empty() and num < minHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        
        if(minHeap.size()  > maxHeap.size() +1 ){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(maxHeap.size()  > minHeap.size() +1 ){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            cout<<"Same \n";
            return double(1.0*(minHeap.top()+maxHeap.top())*0.5);
        }else if(minHeap.size() > maxHeap.size()){
            cout<<"min \n";
            return minHeap.top();
        }else{
            cout<<"max \n";
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */