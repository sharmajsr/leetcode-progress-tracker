class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char>optr, operand;
        for(auto i : exp){
            if( i== 't' or i == 'f' or i=='('){
                operand.push(i);
            }
            else if( i == '&' or i=='|' or i=='!'){
                optr.push(i);
            }
            else if(i==')'){
                if(!optr.empty() and optr.top() =='&'){
                    bool ans = true;
                    while(!operand.empty() and operand.top() != '('){
                        bool top = operand.top() == 't'? true : false;
                        ans = ans & top;
                        operand.pop();
                    }
                    optr.pop();
                    operand.pop();
                    operand.push(ans == true ? 't' : 'f');
                }
                else if(!optr.empty() and optr.top() =='|'){
                    bool ans = false;
                    while(!operand.empty() and operand.top() != '('){
                        bool top = operand.top() == 't'? true : false;
                        ans = ans | top;
                        operand.pop();
                    }
                    optr.pop();
                    operand.pop();
                    operand.push(ans == true ? 't' : 'f');
                }
                else if(!optr.empty() and optr.top() =='!'){
                    bool top = operand.top() == 't'? true : false;
                    bool ans = !top;
                    operand.pop();
                    optr.pop();
                    operand.pop();
                    operand.push(ans == true ? 't' : 'f');
                }
            }
        }
        // cout<<"size : "<<operand.size()<<endl;
        return operand.top() == 't' ? true : false;
    }
};

// |(f,&(t,t))
// operand - | & 
// operatr - (f ( t t