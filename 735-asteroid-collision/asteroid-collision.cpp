class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> v;
        for(auto i : asteroids){
            if(st.empty()){
                st.push(i);
            }
            else if(!st.empty() and st.top() > 0 and i<0 ){
                int val = i;
                bool isSame = true;
                while(!st.empty() and st.top() * i < 0 ){
                    int top = st.top();
                    cout<<top<<" "<<i<<endl;
                    st.pop();
                    if(abs(i) == abs(top)){
                        isSame = false;
                        break;
                    }else if(abs(top) > abs(i)){
                        st.push(top);
                        break;
                    }else{
                        continue;
                    }
                }
                if(isSame){
                    if(st.empty())  st.push(i);
                    else if(!st.empty() and st.top() < 0 )    st.push(i);
                } 
                
            }else {
                 st.push(i);
            }
            
        }
        
        while(!st.empty()){
            v.push_back(st.top());st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};