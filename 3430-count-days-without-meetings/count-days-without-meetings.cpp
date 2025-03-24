class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // vector<long>meets(days+2,0);
        long n = days , ans = 0 , i = 0 ; 
        sort(meetings.begin(),meetings.end());
        while(i<meetings.size()){
            int start = meetings[i][0] ; 
            int end = meetings[i][1];
            int j = i +1 ;
            
            while(j < meetings.size() and meetings[j][0] <= end){
                end = max(end,meetings[j][1]);
                ++j;
            }
            // cout<<start<<" "<<end<<" "<<days<<endl;
            int temp = end - start+1; 
            days -= temp;
            if(j != i+1)    i=j;
            else    ++i;
        }
        // for(auto i : meetings){
        //     int u = i[0];
        //     int v = i[1];
        //     ++meets[u];
        //     --meets[v+1];
        // }
        // for(int i=1;i<=days;i++){
        //     meets[i] = meets[i] + meets[i-1]; 
        // }
        // for(int i=1;i<=days;i++){
        //     if(meets[i] <= 0 ) ++ans;
        // }
        ans = days;
        return ans;
    }
};