class MedianFinder {
public:
priority_queue<int>maxH;
priority_queue<int,vector<int>,greater<int>>minH;
    MedianFinder() {
        // maxH.clear();
        // minH.empty();
    }
    
    void addNum(int num) {
        if(maxH.empty()){
            maxH.push(num);
        }else if(!maxH.empty() and maxH.top()> num){
            maxH.push(num);
        }else{
            minH.push(num);
        }
        if(maxH.size()> 1 + minH.size()){
            minH.push(maxH.top());maxH.pop();
        }
        if(minH.size()> 1+ maxH.size()){
            maxH.push(minH.top());minH.pop();
        }
    }
    
    double findMedian() {
        if(maxH.size() == minH.size()){
            return (maxH.top()+minH.top())*0.5;
        }else if(maxH.size() > minH.size()){
            return maxH.top()*1.0;
        }else{
            return minH.top()*1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */