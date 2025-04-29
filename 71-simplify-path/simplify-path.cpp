class Solution {
public:
    string simplifyPath(string path) {
        string ans,cur;
        stack<string>st,st1;
        int n = path.size();
        for(int i = 1 ; i <n ;i++){
            if(path[i] == '/' and path[i-1] == '/'){
                    continue;
            }
            else if(path[i] == '/'){
                if(cur == "" or cur == "."){
                    cur = "";
                    continue;
                }else if(cur == ".."){
                    if(!st.empty()) st.pop();
                }else{
                    st.push(cur);
                }
                cur = "";
            }
            else{
                cur += path[i];
            }
        }
        // cout<<"after for : "<<cur<<endl;
        if(cur == ".."){
            if(!st.empty()) st.pop();
        }else if(cur==""){}
        else if(cur=="."){}
        else if(cur=="/"){}
        else{
            st.push(cur);
        }
        while(!st.empty()){
            // cout<<st.top()<<endl;
            
            st1.push(st.top());
            st.pop();
        }
        while(!st1.empty()){
            ans += "/" + st1.top() ;
            st1.pop();
        }
        if(ans.size()> 0 and ans[ans.size() -1] == '/' ){
            ans = ans.substr(0,ans.size()-1) ;
        }
        return ans == "" ? "/" : ans;
        
    }
};