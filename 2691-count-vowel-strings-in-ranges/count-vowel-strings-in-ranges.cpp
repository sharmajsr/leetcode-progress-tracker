class Solution {
public:
    bool isVowel(char s){
        if(s == 'a' or s=='e' or s=='i' or s=='o' or s=='u'){
            return true;
        }
        return false;
    }
    bool checkGoodWords(string s){
        if(s.size() == 1 and isVowel(s[0])){
            return true;
        }
        if(s.size() == 2 and isVowel(s[0]) and isVowel(s[1])){
            return true;
        }
        else if(isVowel(s[0]) and isVowel(s[s.size()-1])){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> ans;
        vector<int>vc;
        vc.push_back(0);
        for(int i=0;i<n;i++){
            if(checkGoodWords(words[i])){
                vc.push_back(1);
            }else{
                vc.push_back(0);
            }
        }
        for(int i=1;i<=n;i++){
            vc[i] += vc[i-1];
        }
        
        for(int i=0;i<queries.size();i++){
            int start = queries[i][0], end  = queries[i][1];
            int temp = vc[end+1]-vc[start] ;
            // for(int i=start;i<=end;i++){
            //     if(vc[i]==1)    ++temp;
            // }

            ans.push_back(temp);
        }
        return ans;

    }
};