class MyCalendar {
public:
 vector<pair<int, int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
            for (auto& event : events) {
            // Check if there is an overlap with any existing event
            if((!( event.second<=start or end <= event.first))){
                return false;
            }
        }
        // If no overlap, add the new event
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */