class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int cnt = 0 , n= colors.size();
        for(int i=1;i<n-1;i++){
            if(colors[i] != colors[i-1] and colors[i-1] == colors[i+1]){
                ++cnt;
            }
        }
        if(colors[0] != colors[1] and colors[1] == colors[n-1]) ++cnt;
        if(colors[n-1] != colors[n-2] and colors[n-2] == colors[0]) ++cnt;
        return cnt;
    }
};