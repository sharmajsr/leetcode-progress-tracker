class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>w2freq(26,0);
        for(auto i : words2 ){
            // cout<<i<<" -> ";
            // if(i.size() >1 ){
                vector<int>temp(36,0);
                for(auto j : i){
                    // cout<<j<<" , ";
                    ++temp[j-'a'];
                    w2freq[j-'a'] =max(w2freq[j-'a'],temp[j-'a']);
                }
                
            
            // cout<<endl;
        }
        for(auto i : words1 ){
            cout<<i<<endl;
            bool isThisSubset = true;
            vector<int>w1freq(26,0);
            for(auto j : i ){
                ++w1freq[j-'a'];
            }
            for(int k=0;k<26;k++){
                // if(w2freq[k]>0){
                    // cout<<char(k+'a')<<" "<<w2freq[k]<<" "<<w1freq[k]<<endl;
                    if(w2freq[k] > 0){
                        // w2freq[k]-=w1freq[k];
                        if(w2freq[k]>w1freq[k])
                        isThisSubset = false;
                    } 
                    
                    // if(w2freq[k]>0) isThisSubset=false;
                // }
            }
            
            // for(int k=0;k<26;k++){
            //     cout<<char(k+'a')<<" "<<w1freq[k]<<" "<<w2freq[k]<<endl;
            //     if(w2freq[k]>0) isThisSubset=false;
            // }
            cout<<"isThisSubset "<<isThisSubset<<endl;
            if(isThisSubset)    ans.push_back(i);
            
        }
        return ans;
    }
};