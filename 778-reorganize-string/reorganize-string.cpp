class Solution {
public:
    string reorganizeString(string s) {
        string temp;
        int n = s.size();
        if(n&1) n+=1;
        n/=2;
        if(s.size() <= 1)   return s;
        unordered_map<char,int>um;
        priority_queue<pair<int,char>>maxH;
        for(auto i : s) ++um[i];
        for(auto i : um){
            cout<<i.first<<" " <<i.second<<endl;
            if(i.second>n)   return "";
            maxH.push({i.second,i.first});
        }
        cout<<"size of maxH : " <<maxH.size()<<endl; 
        while(maxH.size()>1){
            // if(temp.size() == 0 ){
                auto top1 = maxH.top();maxH.pop();
                auto top2 = maxH.top();maxH.pop();
                cout<<"top1 : "<<top1.first<<" "<<top1.second<<endl;
                cout<<"top2 : "<<top2.first<<" "<<top2.second<<endl;
                temp += top1.second;
                temp += top2.second;
                cout<<temp<<endl;
                if(top1.first-1 >0 ) maxH.push({top1.first-1,top1.second});
                if(top2.first-1 >0 ) maxH.push({top2.first-1,top2.second});
            // }
            
        }
        if(!maxH.empty())   temp += maxH.top().second;
        return temp;
    }
};