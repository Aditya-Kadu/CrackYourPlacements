class MyQueue {
public:
    stack<int> st;
    stack<int> st2;
    MyQueue() {
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        int ans=st2.top();
        st2.pop();
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    int peek() {
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        int ans=st2.top();
        // st2.pop();
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return st.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */