class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {

        
        
    }

    void push_on_queue(stack<int>& st1, stack<int>& st2, int x) {
        if(st1.empty() && st2.empty()) {
            st1.push(x);
            return;
        }
        if(st1.empty()) {
            push_on_queue(st2,st1,x);
            return;
        }
        st1.push(x);
    }
    
    void push(int x) {
        push_on_queue(st1,st2,x);

    }
    int pop_from_queue(stack<int>& st1, stack<int>& st2) {
        if(st1.empty() && st2.empty()) return -1;
        if(st1.empty()) {
            return pop_from_queue(st2,st1);
            
        }
        while(st1.size()!=1) {
            st2.push(st1.top());
            st1.pop();
        }
        int x = st1.top();
        st1.pop();
        while(st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }
    
    int pop() {
        return pop_from_queue(st1,st2);
        
    }

    int peek_from_queue(stack<int>& st1, stack<int>& st2) {
        if(st1.empty() && st2.empty()) return -1;
        if(st1.empty()) {
            return pop_from_queue(st2,st1);
            
        }
        while(st1.size()!=1) {
            st2.push(st1.top());
            st1.pop();
        }
        int x = st1.top();
        
        while(st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return x;
        
    }
    
    int peek() {
        return peek_from_queue(st1,st2);
        
    }
    
    bool empty() {
        if(st1.empty() && st2.empty()) {
            return true;
        }
        return false;
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