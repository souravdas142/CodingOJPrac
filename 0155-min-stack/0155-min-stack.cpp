class MinStack {
    stack<int> minStack;
        stack<int> st2;
public:
    MinStack() {

        
        
    }
    
    void push(int val) {
        st2.push(val);
        if(minStack.empty()) {
            minStack.push(val);
            return;
        }
        if(val<minStack.top())
            minStack.push(val);
        else
            minStack.push(minStack.top());
        
    }
    
    void pop() {
        if(minStack.empty() && st2.empty()) return;
        minStack.pop();
        st2.pop();
    }
    
    int top() {
        return st2.top();
    }
    
    int getMin() {
        return minStack.top();
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