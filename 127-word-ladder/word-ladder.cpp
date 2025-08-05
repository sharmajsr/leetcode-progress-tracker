class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans= 0 ;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>se;
        for(auto i : wordList){
            if(i != beginWord)
            se.insert(i);
        }
        
        while(!q.empty()){
            auto fr = q.front();q.pop();
            if(fr.first == endWord  ){
                ans = fr.second;
                break;
            }
            for(int i=0;i<fr.first.size();i++){
                bool found =false;
                for(int j=0;j<26;j++){
                    string temp = fr.first;
                    temp[i]=j+'a';
                    if(se.find(temp)!=se.end()){
                        // cout<<fr.first<<" "<<temp<<" "<<fr.second+1<<endl;
                        q.push({temp,fr.second+1});
                        se.erase(temp);
                        found = true;
                        // break;
                    }
                }
            }
        }
        return ans;
    }
};