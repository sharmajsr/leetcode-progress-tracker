class StockSpanner {
public:
// stack<int>st;
vector<int>v;
    StockSpanner() {
        // st.empty();
        v.clear();
    }
    
    int next(int price) {
        // if(st.empty()){
        //     st.push(price);
        //     return 1;
        // }
        // else if(!st.empty() and st.top() > price){
        //     st.push(price);
        //     return 1;
        // }else{
        //     cout<<"Else  : "<<endl;
        //     int cnt = 1 ;
        //     while(!st.empty() and price >= st.top()){
        //         cout<<st.top()<< " " <<price<<endl; 
        //         ++cnt;
        //         st.pop();
        //     }
        //     st.push(price);
        //     return cnt;
        // }
        if(v.size() == 0){
            v.push_back(price);
            return 1;
        }else if(v.size() != 0 and v[v.size()-1]> price){
            v.push_back(price);
            return 1;
        }else{
            int cnt = 1;
            for(int i= v.size()-1 ; i >=0 ;i--){
                if(price >= v[i]){
                    ++cnt;
                }else{
                    break;
                }
            }
            v.push_back(price);
            return cnt;

        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */