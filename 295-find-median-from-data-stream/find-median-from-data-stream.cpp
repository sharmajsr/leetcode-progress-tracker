class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
        maxHeap.empty();
        minHeap.empty();
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 ||  maxHeap.top() >= num){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size() + 1){
            // while(maxHeap.size() > minHeap.size() + 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            // }
        }
        else if(minHeap.size() > maxHeap.size() + 1){
            // while(minHeap.size() > maxHeap.size() + 1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            // }
        }
    }
    
    double findMedian() {

        if(maxHeap.size() == minHeap.size()){
            // cout<<maxHeap.top()<<" "<<minHeap.top()<<endl;
            return (maxHeap.top() + minHeap.top())/2.0;
        }
        else if(minHeap.size()> maxHeap.size()) return minHeap.top();
        // cout<<"yha se "<<maxHeap.top()<<endl;
        // if(minHeap.size()==0)   return maxHeap.top();
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */