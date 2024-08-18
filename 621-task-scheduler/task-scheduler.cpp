class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0 ; 
        int max_element =0 ; 
        int max_count = 0; 
        priority_queue<pair<int,int>>pq;
        unordered_map<char,int>um ; 
        for(auto i : tasks){
            ++um[i];
        }
        for(auto i: um ){
            if( i.second > max_element ) {
                 max_element = i.second;
            }
        }
        for(auto i : um ){
            if(i.second == max_element) ++max_count;
        }
        int nval = (max_element - 1 ) * (n+1) + max_count;
        int ans = tasks.size();
        if( nval > ans) ans = nval;
        return ans;
        
    }
};