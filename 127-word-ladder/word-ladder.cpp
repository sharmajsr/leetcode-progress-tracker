class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>se(wordList.begin(),wordList.end() );
        se.erase(beginWord);
        // for(auto i : wordList) se.insert(i);
        // if(se.find(endWord) == se.end()){
        //     return 0;
        // }
        while(!q.empty()){
            auto itr = q.front();
            q.pop();
            if(itr.first == endWord)
                return itr.second;
            int slen = itr.first.size();
            string it = itr.first;
            for(int i=0;i<slen;i++){
                for(int j=0;j<26;j++){
                    string pref ,suff , cal;
                    pref = it.substr(0,i);
                    suff = it.substr(i+1,slen-i-1);
                    cal = pref + char('a' + j) + suff;
                    if( cal != itr.first && se.find(cal) != se.end()){
                        q.push({cal,itr.second+1});
                        se.erase(cal);
                    }
                }
            }
        }
        return ans;
    }
};