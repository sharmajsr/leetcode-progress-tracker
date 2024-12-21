class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxTime = events[0][1],buttonIndex = events[0][0];
        for(int i=1;i<events.size();i++){
            int diffTime = events[i][1] - events[i-1][1];
            if(diffTime > maxTime ){
                maxTime = diffTime; 
                buttonIndex = events[i][0];
            }else if(diffTime ==  maxTime  and events[i][0] < buttonIndex){
                buttonIndex = events[i][0];
            }
        }
        return buttonIndex;
    }
};