class Solution {
public:
    long long calculateScore(vector<string>& inst, vector<int>& values) {
        long long score = 0 ;
        int n = values.size(),i = 0 ;
        vector<int>vis(n,0);
        while(i<n and i>=0){
            if(vis[i] != 0 )    break;
            vis[i] =1;
            if(inst[i] == "add"){
                score += values[i]; i+=1;
            }
            else if(inst[i] == "jump"){
                i = i+values[i];
            }
        }
        return score;
    }
};