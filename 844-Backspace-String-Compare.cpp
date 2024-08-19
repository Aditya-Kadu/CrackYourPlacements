class Solution {
public:
    stack<char> st;
    stack<char> st2;
    bool backspaceCompare(string s, string t) {
        for(auto x:s){
            if(x>='a' && x<='z'){
                st.push(x);
            }
            else if(!st.empty() && x=='#'){
                st.pop();
            }
            // else if(!st.empty())
        }

        for(auto x:t){
            if(x>='a' && x<='z'){
                st2.push(x);
            }
            else if(!st2.empty() && x=='#'){
                st2.pop();
            }
            // else if(!st.empty())
        }

        string a="";
        while(!st.empty()){
            a+=st.top();
            st.pop();
        }
        string b="";
        while(!st2.empty()){
            b+=st2.top();
            st2.pop();
        }
        return a==b;

    }
};