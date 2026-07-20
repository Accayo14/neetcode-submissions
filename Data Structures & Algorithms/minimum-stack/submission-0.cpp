class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(!minst.empty()) minst.push(min(minst.top(), val));
        else minst.push(val);
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
