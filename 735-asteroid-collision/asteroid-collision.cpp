class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        for(auto i : asteroids){
            if(st.empty()){
                st.push(i);
            }else if(!st.empty() and i > 0 ){
                st.push(i);
            }else if(!st.empty() and i < 0 ){
                int lastEl = 0 ;
                while(!st.empty() and st.top() > 0 and st.top() <= abs(i)){
                    
                    lastEl = st.top();
                    st.pop();
                    if(lastEl == abs(i)){
                        break;
                    }
                }
                if(st.empty()){    //no element in stack
                    if(lastEl < abs(i)){ 
                        st.push(i);
                    }else if(lastEl == abs(i)){
                        continue;
                    }
                }else{     // elements are present in stack
                    // last el was bigger than i
                    //
                    if(st.top()> 0 ){
                        continue;
                    }
                    else{
                        if(abs(i) == lastEl){ // st has neg element at top, but last popped element has same quantity
                            continue;
                        }else{  // st has neg element at top, but last popped element has smaller quantity
                            st.push(i);
                        }
                    }
                }   
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};