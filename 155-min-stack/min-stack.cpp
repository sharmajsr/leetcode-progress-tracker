class MinStack {
public:
stack<int>st1,st2;
    MinStack() {    
        st1.empty();
        st1.empty();
    }
    
    void push(int val) {
        st1.push(val);
        if(!st2.empty())    st2.push(st2.top() > val ? val : st2.top());
        else st2.push(val);
    }
    
    void pop() {
        st1.pop();
        st2.pop();
    }
    
    int top() {

        return st1.top();
    }
    
    int getMin() {
        return st2.top();
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