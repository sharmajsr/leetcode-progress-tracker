class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0 , n = s.size();
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                string st = s.substr(i,j-i+1);
                
                int ones = 0 ;
                int zeros = 0 ;
                for(auto p : st){
                    if( p == '0' ) ++zeros;
                    else            ++ones;
                }
                // cout<<st<<" "<<zeros<<" "<<ones<<endl;
                if(zeros <= k || ones <= k)  ++ans;
            }
        }
        return ans;
    }
};