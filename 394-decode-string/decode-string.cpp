class Solution {
public:
    string decodeString(string s) {
        stack<int>st1;
        stack<string>st2;
        for(int j= 0; j < s.size(); j++ ){
            auto i = s[j];
            // cout<<i<<endl;
            if(i >= '0' and i<='9'){
                int k = j;
                int val = 0;
                while( s[k] >='0' and s[k] <='9'){
                    val = val*10 + s[k]-'0';
                    ++k;
                }
                st1.push(val);
                j=k-1;
            }else{
                if( i == ']'){
                    string cur, temp ;
                    while(!st2.empty() and st2.top() != "["){
                        cur = st2.top() + cur;st2.pop();
                    }
                    // cout<<"prev cur :  " <<cur<<endl; 
                    // reverse(cur.begin(),cur.end());
                    // cout<<"prev cur rev :  " <<cur<<endl; 
                    int k = st1.top(); st1.pop();
                    for(int i=0; i<k  ; i++){
                        temp +=cur;
                    }
                    st2.pop();
                    // reverse(temp.begin(),temp.end());
                    // cout<<"Pushing  : "<<temp<<endl;
                    st2.push(temp);
                }else{
                    string p1 = string() + i ;
                    // cout<<"p1 : "<<p1<<endl;
                    st2.push(p1);
                }
            }
        }
        string ans;
        while(!st2.empty()){
            ans = st2.top() + ans;
            st2.pop();
        }
        return ans;
    }
};