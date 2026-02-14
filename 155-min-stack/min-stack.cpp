class MinStack {
public:
    stack<long long>st;
    long long mini = LLONG_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if(mini<val)
                st.push(val);
            else
            {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        long long n = st.top();
        st.pop();
        if(n<mini)
            mini = 2LL * mini - n;
    }
    
    int top() {
        if(st.empty())
            return -1;
        long long n = st.top();
        if(n>mini)
            return (int)n;
        return (int)mini;
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */