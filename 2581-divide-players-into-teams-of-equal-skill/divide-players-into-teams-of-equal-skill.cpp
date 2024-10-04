class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long tsum = 0 , n = skill.size() , ans= 0; 
        unordered_map<int,int>um;
        int numberOfTeams = n / 2;
        for(auto i : skill){ 
            tsum += i;
            ++um[i];
        }
        int sumOfEachTeam = tsum / numberOfTeams;
        for(auto i : skill){
            int requiredSkill = sumOfEachTeam - i;
            if(um.find(requiredSkill) != um.end()){
                --um[requiredSkill];
                // --um[i];
                if(um[requiredSkill] == 0 ) um.erase(requiredSkill);
                // if(um[i] == 0 ) um.erase(requirediSkill);
                ans += (i * requiredSkill);
            }
            else{
                return -1;
            }
        }
        return ans/2 ;

    }
};