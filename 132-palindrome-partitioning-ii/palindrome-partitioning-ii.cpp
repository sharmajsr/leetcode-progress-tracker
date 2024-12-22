class Solution {
public:
    vector<vector<int>>v;
    vector<vector<int>>palin;
    bool is_palindrome1(string s , int i ,int  j ){
        if(i>=j)    return true;
        if( palin[i][j] != -1)  return palin[i][j];
        while(i<j){
            if(s[i] != s[j])    return palin[i][j] = false ;
            ++i;
            --j;
        }
        return  palin[i][j]= true ;
    }
    bool is_palindrome(string& s, int i, int j) {
		if (i >= j) return true;
		if (palin[i][j] != -1) return palin[i][j];
		if (s[i] == s[j]) return palin[i][j] = is_palindrome(s, i + 1, j - 1);
		return palin[i][j] = false;
	}
    int solve(string s, int i ,int j){
        if(i>=j)    return v[i][j] = 0;
        if(v[i][j] != -1) return v[i][j];
        if(is_palindrome(s,i,j))    
            return v[i][j]=0;
        
        int mini = INT_MAX;
        for(int k=i;k<=j-1;k++){
            if( is_palindrome(s,i,k)){
                int t1 ,t2;
                if(v[k+1][j] == -1) v[k+1][j] = solve(s,k+1,j);
                // t1 = v[i][k];
                t2 = v[k+1][j];
                int temp =  t2 +1;
                mini = min(mini, temp);
            }
        }
        return v[i][j]=mini;
    }
    int minCut(string s) {
        v.resize(s.size(),vector<int>(s.size(),-1));
        palin.resize(s.size(),vector<int>(s.size(),-1));
        return solve(s,0,s.size()-1);
    }
};