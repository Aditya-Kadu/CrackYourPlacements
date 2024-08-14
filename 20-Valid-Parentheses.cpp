class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for( auto x: s){
            if(x=='(' || x=='[' || x=='{'){
                st.push(x);
            }
            if(x==')' && !st.empty() && st.top()=='('){
                st.pop();
            }else if(x==')') st.push(')');
            if(x==']' && !st.empty() && st.top()=='['){
                st.pop();
            }else if(x==']') st.push(']');
            if(x=='}' && !st.empty() && st.top()=='{'){
                st.pop();
            }else if(x=='}') st.push('}');
        }
        return st.empty();
    }
};