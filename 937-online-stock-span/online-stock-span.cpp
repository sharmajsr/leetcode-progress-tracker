class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        st.empty();  
    }
    
    int next(int price) {
        
        int ans = 1;
        if(st.empty()){
            st.push({price,1});
            return ans;
        }
        else if(st.top().first > price){
            st.push({price,1});
            return ans;
        }
        else{
            int del = 0;
            while(!st.empty() and price >= st.top().first ){
                    del += st.top().second;
                    st.pop();
                    
            }
            ans = del+1;
            st.push({price,ans});
            return ans;
        }
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */