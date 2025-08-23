class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int low = 0, high = n-1 , ans= 0 ;
        sort(people.begin(), people.end());
        while(low < high){
            // cout<<low<<
            int t = people[low] + people[high];
            if( t <= limit ){
                ans += 1;
                ++low;
                --high;
            }else{
                ans += 1;
                --high;
            }
        }
        if(low==high) ++ans;
        return ans;
    }
};