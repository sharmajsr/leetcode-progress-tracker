class Solution {
public:
    char fin(char let, int pos){
        if(pos == 0) return let;
        int sign = (pos > 0) ? 1 : -1 ;
        int rem = sign * (abs(pos)%26);
        int letIndex = let - 'a';
        int finalPos = letIndex + rem;
        finalPos %= 26;
        if(finalPos >= 0) return 'a' + finalPos;
        return 'z' + finalPos+1;

    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        string ans ;
        vector<int>pos(n+1,0);
        
        


        for(auto i:shifts){
            int startIndex =i[0];
            int endIndex = i[1];
            int direction = i[2];
            // for(int i=startIndex ; i <=endIndex;i++){
            //     if(direction == 0){
            //         pos[i] -=1;
            //     }
            //     else{
            //         pos[i] +=1;
            //     }
            // }
            pos[startIndex]  += (direction == 1) ? 1 : -1; 
            pos[endIndex +1] -= (direction == 1) ? 1 : -1; 
        }
        int prefix = 0;
        for(int i=0;i<n;i++){
            prefix += pos[i];
            cout<<s[i]<<" "<<pos[i]<<endl;
            ans += fin(s[i],prefix);
        }   
        return ans;
    }
};