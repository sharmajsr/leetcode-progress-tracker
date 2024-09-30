class CustomStack {
public:
vector<int>v;
stack<int>st;

//  array -> [ 94 , 0 , 0 , 0 , 0 , 0 , 0   ]
//  stack -> [ 83 ]
    CustomStack(int maxSize) {
        for(int i=0;i<maxSize;i++){
            v.push_back(0);
        }
    }
    
    void push(int x) {
        if( st.size() ==  v.size()) return;
        st.push(x);
        
    }
    
    int pop() {
        if(st.size() == 0  )  return -1;
        
        int val =  st.top() + v[st.size()-1];
        v[st.size()-1] = 0 ;
        st.pop();
        return val;
    }
    
    void increment(int k, int val) {
        int stackSize = st.size(); //4
        if( k > st.size() ) k = stackSize; // k = 4
        for(int i=0; i<k and i< st.size() ; i++){
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */