class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 =s2.size();
        vector<int>vec(26,0);
        vector<int>vec1(26,0);
        for(int i=0;i<n1;i++){
            ++vec[s1[i]-'a'];
            cout<<s1[i]<<" "<<vec[s1[i]-'a']<<endl;
        }
        int i=0,j=0;
        while(j<n2){ 
            // cout<<s2[j]<<" "<<j<<endl;
            if(n1 > (j-i )){
                cout<<"isnide if "<<endl;
                ++vec1[s2[j]-'a'];
                ++j;
            }
            else if(n1 == (j-i)){
                cout<<"isnide else "<<endl;
                --vec1[s2[i]-'a'];
                ++vec1[s2[j]-'a'];
                ++i;
                ++j;
            }
            bool ans = true;
            for(int k=0;k<26;k++){
                
                if(vec[k] != vec1[k]){
                    // cout<<j<<" "<<k<<" "<<vec[k]<<" "<<vec1[k]<<endl;
                    ans= false;
                }
            }
            if(ans == true ) return true;

        }
        return false;
    }
};