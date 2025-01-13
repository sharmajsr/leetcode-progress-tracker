class MinStack {
public:
stack<pair<int,int>>s1;
stack<pair<int,int>>s2;
    MinStack() {
        s1.empty();
        s2.empty();
    }
    
    void push(int val) {
        if(s1.empty()) {
            s1.push({val,s1.size()});
            s2.push({val,s1.size()});
        }else if (!s2.empty() and s2.top().first > val ){
            s1.push({val,s1.size()});
            s2.push({val,s1.size()});
        }else if(!s2.empty() and s2.top().first <= val){
            s1.push({val,s1.size()});
            s2.push({s2.top().first,s2.top().second});
        }
        // else{
            // s1.push({val,s1.size()});
            // s2.push({s1.top().first,s1.top().second});
            // if(!s2.empty()) s2.push({ s2.top().first, s2.top().second});
            // else s2.push({val,s1.size()});
            // if(s1.top().first <=val){
            //     s2.push({val,s1.size()});
            // }
        // }
    }
    
    void pop() {
        // if(s1.top().second == s2.top().second){
            s1.pop();
            s2.pop();
        // }else{
        //     s1.pop();
        // }
    }
    
    int top() {
        return s1.top().first;
    }
    
    int getMin() {
        return s2.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */