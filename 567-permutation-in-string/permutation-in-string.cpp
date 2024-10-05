class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int,int>um1,um2,um3;
        for(auto i : s1)  ++um1[i-'a'];
        for(auto i : s2)  ++um3[i-'a'];
        for(auto i : um1){
            if(um1[i.first] > um3[i.first]){
                return false;
            }
        }
        um2 = um1;
        bool ans = false;
        int n = s2.size() , m = s1.size();
        
        for(int i=0 ; i<n; i++){
            int num = s2[i]-'a';
            // cout<<i<<" "<<s2[i]<<endl;
            if(um1.find(num) != um1.end()){
                --um1[num];
                if(um1[num] == 0 )  um1.erase(num);
                int j = i+1;
                while(j<n and um1.size() > 0 ){
                    num = s2[j]-'a'; 
                    if(um1.find(num) != um1.end()){
                        --um1[num];
                        if(um1[num] == 0 )  um1.erase(num);
                    }else{
                        break;
                    }
                    ++j;
                }
                if(um1.size() == 0){
                    ans = true;
                    return ans;
                    break;
                }else{
                    um1 = um2;
                }
            }
            if(ans == true){
                
            }

        }
        return ans;
    }
};