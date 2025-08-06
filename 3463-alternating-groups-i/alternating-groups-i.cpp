class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int cnt = 0 , n= colors.size();
        for(int i= 0 ;i<2;i++)  colors.push_back(colors[i]);
        for(int i =1 ; i < colors.size()-1 ; i++){
            if(colors[i-1] == colors[i+1] and colors[i] != colors[i+1]){
                // cout<<"Fount at "<<i<<endl;
                ++cnt;
            }
        }
        return cnt;
    }
};