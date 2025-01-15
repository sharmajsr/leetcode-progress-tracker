class MedianFinder {
public:
    priority_queue<int>maxH;
    priority_queue<int,vector<int>,greater<int>>minH;
    MedianFinder() {
        maxH.empty();
        minH.empty();
    }
    
    void addNum(int num) {
        maxH.push(num);
        // all elemets in maxH is less than all elements in minH
        if(!maxH.empty() and !minH.empty() and minH.top() < maxH.top()){
            minH.push(maxH.top());
            maxH.pop();
        }
        // cout<<maxH.size()<<" "<<minH.size()<<endl;
        int diff1 = maxH.size()-minH.size();
        int diff2 = minH.size()- maxH.size();
        // should not have difference more than 1
        if(diff1 > 1){
            minH.push(maxH.top());
            maxH.pop();
        }
        else if( diff2 > 1){
            maxH.push(minH.top());
            minH.pop();
        }
        // cout<<maxH.size()<<" .. "<<minH.size()<<endl;
        // cout<<maxH.size()<<" "<<minH.size()<<" "<<maxH.top()<<" "<<minH.top()<<endl;
    }
    
    double findMedian() {
        if(maxH.size() == minH.size()){
            // cout<<"eq : " <<maxH.top()<< " "<<minH.top()<<endl; 
            return double((maxH.top() + minH.top() ) * 0.5 ) ;
        }
        
        else if(maxH.size() > minH.size()){
            // cout<<"uneq : " <<maxH.top()<< " "<<minH.top()<<endl; 
            return maxH.top();
            
        }
        else{
            // cout<<"uneq : " <<maxH.top()<< " "<<minH.top()<<endl; 
            return minH.top();
        }
        // return 1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */