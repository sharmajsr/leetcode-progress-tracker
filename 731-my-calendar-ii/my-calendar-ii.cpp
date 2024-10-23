class MyCalendarTwo {
public:
vector<pair<int,int>>overlapped;
vector<pair<int,int>>events;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto event:overlapped){
            if(not(( event.second <=start) or (end <= event.first))){
                return false;
            }
        }
        for(auto event:events){
            if(not(( event.second <=start) or (end <= event.first))){
                overlapped.push_back({max(start,event.first) , min(end,event.second)});
            }
        }


        events.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */