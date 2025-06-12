class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    MedianFinder() {
        maxH.empty();
        minH.empty();
    }

    void addNum(int num) {
        if (maxH.empty()) {
            maxH.push(num);
        } else if (!maxH.empty() and num > maxH.top()) {
            minH.push(num);
        } else {
            maxH.push(num);
        }
        if( maxH.size() >  minH.size() +1 ) {
            minH.push(maxH.top());
            maxH.pop();
        } 
        else if ( minH.size() > maxH.size() + 1) {
            maxH.push(minH.top());
            minH.pop();
        }
        // cout<<num<<" "<<
    }

    double findMedian() {
        if (minH.size() == maxH.size()) {
            return (maxH.top() + minH.top()) * 0.5;
        } else if (maxH.size() > minH.size()) {
            return maxH.top();
        } else {
            return minH.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */