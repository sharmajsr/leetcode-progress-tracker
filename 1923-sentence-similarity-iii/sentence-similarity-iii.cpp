class Solution {
public:
    bool isAllPref(vector<string>s1,vector<string>s2,bool suff){
        int st = 0 ;
        if(suff){
            reverse(s1.begin(),s1.end());
            reverse(s2.begin(),s2.end());
        }
        for(auto i : s2){
            if(s1[st] == i){
                ++st;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool solve(vector<string>s1,vector<string>s2){
        
        if(s2.size() > s1.size()){
            vector<string> temp ; 
            temp =s1;
            s1 = s2;
            s2 = temp;
        } // s1 is always bigger
        bool isAllInPrefix = false ,isAllInSuffix = false;
        if(isAllPref(s1,s2,false)  or isAllPref(s1,s2,true))  return true;
        int i = 0 , j =s1.size()-1, k = 0 ,l = s2.size()-1;
        while(k <=l and i<=j){
            cout<<k<<" "<<l<<" "<<i<<" "<<j<<endl;
            if(s2[k] == s1[i]){
                ++i;
                ++k;
            }else if(s2[l] == s1[j]){
                --j;
                --l;
            }else{
                return false;
            }
        }
        return true;
    }
    vector<string>getSplitSentence(string str){
        vector<string>result;
        int start = 0 ;
        for(int i=0;i<str.size();i++){
            if(str[i] == ' '){
                string temp = str.substr(start,i-start);
                result.push_back(temp);
                start = i + 1;
            }
        }
        string temp = str.substr(start,str.size()-start);
        result.push_back(temp);
        return result;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int commonWordsCount = 0 , c1 = 0 ,c2 = 0 ;
        vector<string>s1,s2;
        s1 = getSplitSentence(sentence1);
        s2 = getSplitSentence(sentence2);
        bool res = solve(s1,s2);
        return res;
        if(s1.size() == s2.size() and s1 != s2 )    return false;
        bool prefix = false, suffix = false;
        unordered_map<string,int>um;
        for(auto i : s1) ++um[i];
        for(auto i : s2) ++um[i];
        for(auto i : um) if(i.second%2 == 0 )   ++commonWordsCount;  
        for(int i=0; i<s1.size() and i <s2.size() ;i++){
            if(s1[i] == s2[i]){
                ++c1;
                
            }
        }
        int j = s1.size() - 1 , k = s2.size() - 1;
        while(j>= 0 and k >=0){
            if(s1[j] == s2[k]){
                ++c2;
            }else{
                break;
            }
            --j;
            --k;
        }
        if(commonWordsCount == 0 and s1.size()>0 and s2.size()>0) return false;
        return c1+c2 == commonWordsCount;
    }
};

// when it is valid
//  - only prefix is present
//  - only suffix is present
// - both prefix and suffix is present
// My name is Shubham Sharma
// My is Sharma
// "UI wqhw Lf"
// "ezzXqqEQcS"
// s1 = "c BDQ r h p Ny"
// s2 = "c h p Ny"