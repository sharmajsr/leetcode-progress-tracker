class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int i =0 , j =n-1 ,ans = 0 ;
        sort(people.begin(),people.end());
        while(i<=j){
            int sum = people[i] + people[j];
            if(sum > limit){
                // cout<<"Greater "<<sum<<endl;
                ++ans;
                --j;
            }else{
                // cout<<"LTE "<<sum<<endl;
                ++ans;
                ++i;
                --j;
            }
        }
        return ans;
    }
};
// 3 3 4 5
// 1 2 2 3
//    