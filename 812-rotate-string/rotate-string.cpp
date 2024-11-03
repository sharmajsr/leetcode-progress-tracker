class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size() , m = goal.size();
        if( n != m )    return false;
        for(int i=0;i<n;i++){
            string s1 = s.substr(i+1) + s.substr(0,i+1);
            // cout<<s1<<endl;
            if(s1 == goal)  return true;
        }
        return false;
    }
};