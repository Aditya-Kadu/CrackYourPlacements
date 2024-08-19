//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for(auto x: S){
            if(x>='0' && x<='9'){
                st.push(x-'0');
            }
            else{
                if(x=='*'){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    st.push(op2*op1);
                }
                else if(x=='/'){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    st.push(op2/op1);
                }
                if(x=='+'){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    st.push(op1+op2);
                }
                if(x=='-'){
                    int op1=st.top();
                    st.pop();
                    int op2=st.top();
                    st.pop();
                    st.push(op2-op1);
                }
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends