class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto x: tokens){
            
            if(x==\*\ || x==\/\ || x==\+\ || x==\-\){
                if(x==\*\){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    st.push(op2*op1);
                }
                else if(x==\/\){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    st.push(op2/op1);
                }
                if(x==\+\){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    st.push(op1+op2);
                }
                if(x==\-\){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    st.push(op2-op1);
                }
            }
            else{
                st.push(stoi(x));
            }
        }
        // int ans=0;
        // int ind=0;
        // while(!st.empty()){
        //     ans+=(st.top()*pow(10,ind));
        //     st.pop();
        //     ind++;
        // }
        // return ans;
        return st.top();
    }
    int prec(char ch){
        if(ch=='/' || ch=='*') return 2;
        else if(ch=='+' || ch=='-') return 1;
        return -1;
    }
    int calculate(string s) {
        vector<string> pro;
        stack<char> st;
        int num=0;
        bool flag=false;
        for(auto x: s){
            if(isdigit(x)){
                num=num*10 + (x-'0');
                flag=true;
            }
            else if(x==' '){
                if(flag){
                    pro.push_back(to_string(num));
                    num=0;
                    flag=false;
                }
            }
            else{
                if(flag){
                    pro.push_back(to_string(num));
                    num=0;
                    flag=false;
                }
                while(!st.empty() && prec(x)<=prec(st.top())){
                    pro.push_back(string(1, st.top()));
                    st.pop();
                }
                st.push(x);
                num=0;
            }
        }

        if(flag){
            pro.push_back(to_string(num));
        }

        while(!st.empty()){
            pro.push_back(string(1, st.top()));
            st.pop();
        }

        // cout<<pro;
        for(auto z: pro){
            cout<<z<<endl;
        }

        return evalRPN(pro);
    }
};